//you can just use WER_w or WER_a to use them directly, if you want to use the value of the function you have to cast it.
#ifndef ERRORWRAPPER
#define ERRORWRAPPER

#include <wchar.h>
#include <stdarg.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>

void winErrorCheck8(int line, ...);
void winErrorCheck16(int line, ...);
int hashmod20char(char* string);
int hashmod20wchar(wchar_t* string);

#ifdef UNICODE
#define WER WER_16
#else
#define WER WER_8
#endif
#ifndef REMOVE_ERROR_WRAPPERS
#define WER_8(function) ({union {typeof(function) temp; long long int temp0;} a; a.temp0 = 0; a.temp = function; winErrorCheck8(__LINE__, __FILE__, (void*)&a.temp, #function); a.temp;})
//one day this looming error "ISO C forbids braced-groups within expressions" will be resolved
#define WER_16(function) ({union {typeof(function) temp; long long int temp0;} a; a.temp0 = 0; a.temp = function; winErrorCheck16_interum(__LINE__, __FILE__, (void*)&a.temp, #function); a.temp;})
#define winErrorCheck16_interum(a, b, c, d) winErrorCheck16_interum2(a, b, c, d)
#define winErrorCheck16_interum2(a, b, c, d) winErrorCheck16(a, L##b, c, L##d)
#else
#define WER
#endif

#endif