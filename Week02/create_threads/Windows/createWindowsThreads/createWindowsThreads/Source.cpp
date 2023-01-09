// PROG71040 W23 - Week02 - Prof SteveH
//
//adapted from: https://docs.microsoft.com/en-us/windows/win32/procthread/creating-threads

#include "Source.h"
#include <tchar.h>
#include <strsafe.h>

int _tmain()
{
    PMYDATA pDataArray[MAX_THREADS];            //an array of structures - 1 each to send to the thread     
    DWORD   dwThreadIdArray[MAX_THREADS];   //holds the newly created threadID
    HANDLE  hThreadArray[MAX_THREADS];          //holds a handle (pointer) to the new thread

    // Create MAX_THREADS worker threads
    for (int i = 0; i < MAX_THREADS; i++)
    {
        // Allocate memory for thread data.
        pDataArray[i] = (PMYDATA)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(MYDATA));
        if (pDataArray[i] == NULL)      //if alloc fails, give up and exit.
            ExitProcess(2);

        // Generate unique (dummy) data for each thread to work with. 
        pDataArray[i]->dataPoint0 = i;
        pDataArray[i]->dataPoint1 = i + 100;

        // Create the thread...
        // from: https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread
        // the return is "If the function succeeds, the return value is a handle to the new thread."
        hThreadArray[i] = CreateThread(
            NULL,                   // default security attributes
            0,                      // use default stack size  
            MyThreadFunction,       // thread function name
            pDataArray[i],          // argument to thread function 
            0,                      // use default creation flags 
            &dwThreadIdArray[i]);   // returns the thread identifier 

        if (hThreadArray[i] == NULL)
            ExitProcess(3);
    } // End of main thread creation loop.

    // if we exit now, all the threads running in our process will just disappear.
    // so, we wait till they all finish.
    WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);

    // Close all thread handles and free memory allocations.
    for (int i = 0; i < MAX_THREADS; i++)
    {
        CloseHandle(hThreadArray[i]);
        if (pDataArray[i] != NULL)
        {
            HeapFree(GetProcessHeap(), 0, pDataArray[i]);
            pDataArray[i] = NULL;    // Ensure address is not reused.
        }
    }

    return 0;
}


DWORD WINAPI MyThreadFunction(LPVOID lpParam)
{
    HANDLE hStdout;
    PMYDATA pDataArray;

    TCHAR msgBuf[BUF_SIZE];
    size_t cchStringSize;
    DWORD dwChars;

    // Make sure there is a console to receive output results.  (we used windows.h, so this is technically a windows program (traditionally GUI)
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdout == INVALID_HANDLE_VALUE)
        return 1;

    // Cast the parameter to the correct data type (it comes in as a void pointer)
    pDataArray = (PMYDATA)lpParam;

    // Print the parameter values using thread-safe functions.
    StringCchPrintf(msgBuf, BUF_SIZE, TEXT("Parameters = %d, %d\n"),
        pDataArray->dataPoint0, pDataArray->dataPoint1);
    StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
    WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);

    return 0;
}


