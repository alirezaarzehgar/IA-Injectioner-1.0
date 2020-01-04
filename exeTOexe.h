#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

#ifndef EXETOEXE_H_
#define EXETOEXE_H_

void seyArgError();
int xxd_i(char* argv1, char* argv2);
void exeTOexeInP_c();
void programs_run(char* argv);
bool istrue(const char* str1, char* str2, int a);
bool file_exist(char* FILE_NAME);
bool isExecutable(char* FILE_NAME);
bool isImage(char* FILE_NAME);

#endif
