#include "exeTOimage.h"

#ifndef EXETOPYTHON_H_
#define EXETOPYTHON_H_

bool isPython(char* FILE_NAME);
void exeTOpytonInP_c(char** argv);
bool isRuby(char* FILE_NAME);
void exeTOrubyInP_c(char** argv);
bool isPerl(char* FILE_NAME);
void exeTOPerlInP_c(char** argv);

#endif
