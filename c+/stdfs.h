#ifndef _CP_FS
#define _CP_FD

#include "c+/stdtype.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int fexists(char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

char**flist(char*dirname,u64*count){
    DIR *d;
    struct dirent *dir;
    char **file_list = NULL;
    u64 size = 0;
    u64 capacity = 10;
    file_list = (char**)malloc(capacity * sizeof(char*));
    if (!file_list) {
        return NULL;
    }
    d = opendir(dirname);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
                continue;
            if (size >= capacity) {
                capacity *= 2;
                char**temp = (char **)realloc(file_list, capacity * sizeof(char *));
                if (!temp) {
                    for (int i = 0; i < size; ++i) {
                        free(file_list[i]);
                    }
                    free(file_list);
                    closedir(d);
                    return NULL;
                }
                file_list = temp;
            }
            file_list[size] = strdup(dir->d_name);
            if (!file_list[size]) {
                for (int i = 0; i < size; ++i) {
                    free(file_list[i]);
                }
                free(file_list);
                closedir(d);
                return NULL;
            }

            size++;
        }
        closedir(d);
    }
    *count = size;
    return file_list;
}
char*freadAll(char*filename,u64 *size){
    FILE*f=fopen(filename,"rb");
    if(f==NULL){
        return NULL;
    }
    fseek(f, 0, SEEK_END);
    *size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char*buf = (char*) malloc(*size*sizeof(char));
    if(buf==NULL){
        fclose(f);
        return NULL;
    }
    fread(buf, 1,*size, f);
    fclose(f);
    return buf;
}
void fput(char*filename, char*mode,char*content){
    FILE*f= fopen(filename,mode);
    fprintf(f,"%s",content);
    fclose(f);
}







#endif