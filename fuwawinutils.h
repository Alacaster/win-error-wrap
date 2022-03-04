#ifndef FUWAWINUTILS
#define FUWAWINUTILS
//warning this flushes the stdin file buffer
void waitForKey();
int custom_strncmp(char* positiveString, char* negativeString, size_t size);
int custom_wstrncmp(wchar_t* positiveLString, wchar_t* negativeLString, size_t size);
#endif