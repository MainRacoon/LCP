#ifndef _CP_STDARR
#define _CP_STDARR

#include <stdlib.h>
#include "c+/stdtype.h"

#define ArrayTypeNew(elementType,arrayTypeName) typedef struct{elementType*array;uint64 size,len;}arrayTypeName;arrayTypeName arrayTypeName##_new(){return(arrayTypeName){(elementType*)malloc(0),0,0};}void arrayTypeName##_resize(arrayTypeName*array,uint64 elements){if(array->len>array->size-elements){array->len=elements;}array->size=elements;array->array=(elementType*)realloc(array->array,sizeof(elementType)*array->size);}void arrayTypeName##_append(arrayTypeName*array,elementType element){array->array[array->len]=element;array->len++;}void arrayTypeName##_add(arrayTypeName*array,elementType element,uint64 index){ for(uint64 i=array->len;i>index;i++){array->array[i]=array->array[i-1];}array->array[index]=element;array->len++;}int arrayTypeName##_remove(arrayTypeName*array,uint64 index){if(index>=array->len){return 1;}for(uint64 i=index;i<array->len-1;++i){array->array[i]=array->array[i+1];}array->len--;return 0;}

#endif