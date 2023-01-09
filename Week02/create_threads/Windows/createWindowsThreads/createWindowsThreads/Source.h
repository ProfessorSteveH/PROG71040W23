// PROG71040 W23 - Week02 - Prof SteveH
//

#pragma once
#include <windows.h>

#define MAX_THREADS 20
#define BUF_SIZE 255

// this will be the function that is executed by each thread we create:
DWORD WINAPI MyThreadFunction(LPVOID lpParam);

// Sample custom data structure for threads to use.
// This is passed by void pointer so it can be any data type
// that can be passed using a single void pointer (LPVOID).
typedef struct MyData {
    int dataPoint0;
    int dataPoint1;
} MYDATA, * PMYDATA;
