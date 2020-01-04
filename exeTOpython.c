#include "exeTOpython.h"

bool isPython(char* FILE_NAME)
{
	if(fopen(FILE_NAME, "r") != NULL && strstr(FILE_NAME, ".py")) return true;
	else return false;
}

void exeTOpytonInP_c(char** argv)
{
	exeTOexeInP_c();
}

bool isRuby(char* FILE_NAME)
{
        if(fopen(FILE_NAME, "r") != NULL && strstr(FILE_NAME, ".rb")) return true;
        else return false;
}

void exeTOrubyInP_c(char** argv)
{
        exeTOexeInP_c();
}

bool isPerl(char* FILE_NAME)
{
        if(fopen(FILE_NAME, "r") != NULL && strstr(FILE_NAME, ".pl")) return true;
        else return false;
}

void exeTOPerlInP_c(char** argv)
{
        exeTOexeInP_c();
}

