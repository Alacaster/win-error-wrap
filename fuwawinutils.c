#include <windows.h>
#include "fuwawinutils.h"

void waitForKey(){
    HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
    FlushFileBuffers(in);
    INPUT_RECORD a;
    DWORD g;
    while(1){
        ReadConsoleInputW(in, &a, 1, &g);
        if(a.EventType == KEY_EVENT){
            exit(0);
        }
    }
}

int custom_strncmp(char* positiveString, char* negativeString, size_t size){
    int diff = 0;
    for(int i = 0; (size_t)i < size; i++){
        diff += positiveString[i] - negativeString[i];
    }
    return diff;
}

int custom_wstrncmp(wchar_t* positiveLString, wchar_t* negativeLString, size_t size){
    int diff = 0;
    for(int i = 0; (size_t)i < size; i++){
        diff += positiveLString[i] - negativeLString[i];
    }
    return diff;
}