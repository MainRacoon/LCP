#ifndef _CP_STDSTR
#define _CP_STDSTR
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "c+/stdtype.h"

char*strformat(char*format,...) {
    va_list args;
    va_list args_copy;
    u64 needed;
    char*buffer;
    va_start(args, format);
    va_copy(args_copy, args);
    needed = vsnprintf(NULL, 0, format, args) + 1;
    va_end(args);
    buffer = (char*)malloc(needed);
    if (!buffer) {
        va_end(args_copy);
        return NULL;
    }
    vsnprintf(buffer, needed, format, args_copy);
    va_end(args_copy);
    return buffer;
}
char*strconcat(char* string1,u64 len1, char* string2,u64 len2) {
    char* result = (char*)malloc(len1 + len2 + 1);
    if (result == NULL) {
        return NULL;
    }
    strncpy(result, string1, len1);
    strncpy(result+len1, string2, len2);
    result[len1+len2]=0;
    return result;
}
bool strcharIn(char*string,u64 len, char c){
    for (u64 i = 0; i < len; ++i) {
        if(string[i]==c){
            return true;
        }
    }
    return false;
}
bool strcharInAt(char*string,u64 len, char c,u64*at){
    for (u64 i = 0; i < len; ++i) {
        if(string[i]==c){
            *at=i;
            return true;
        }
    }
    return false;
}
char* strsubstring(char *str,u64 len, u64 from, u64 count) {
    if (from+count > len) {
        return NULL;
    }
    char *newStr = (char *)malloc((count+1) * sizeof(char));
    strncpy(newStr,str+from,count);
    newStr[count]=0;
    return newStr;
}
char* strsubstringrange(char *str,u64 len, u64 from, u64 to) {
    if (to > len) {
        return NULL;
    }
    char *newStr = (char *)malloc((to-from+1) * sizeof(char));
    strncpy(newStr,str+from,(to-from));
    newStr[to-from]=0;
    return newStr;
}
char*strcopy(char* source) {
    char* copy = (char*)malloc((strlen(source) + 1) * sizeof(char));
    strcpy(copy, source);
    return copy;
}
char*strctcp(char c){
    char* str = (char*)malloc(2 * sizeof(char));
    str[0] = c;
    str[1] = '\0';
    return str;
}
#define streq(str1, str2) (strcmp(str1, str2)==0)
#endif

