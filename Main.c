#include "exeTOexe.h"
#include "exeTOimage.h"
#include "exeTOpython.h"

int main(int argc, char** argv)
{
	printf(BANNER);

	if(argc == 1)
	{
		printf("IA-Injectioner-1.0: \033[91mfatal error:\033[0m no input files\n"
		       "IAInjectioner <executable file, .py, .pl, .rb> <another file (executable ,image, .py, .rb, .pl)> [output name]\n");
		return 0;
	}

        if(
        istrue(argv[1], "-help" , strlen(argv[1])) ||
        istrue(argv[1], "--help", strlen(argv[1])) ||
        istrue(argv[1], "help"  , strlen(argv[1])) ||
        strlen(argv[1]) == 1 && argv[1][0] == 'h'  ||
        istrue(argv[1], "-h"  , strlen(argv[1])))
        {
                // sey help for useing
                seyArgError();
		return 0;
        }

         // create a heder file from binary variable of first and second file (.p1, .p2) {exeTOexe.c | exeTOexe.h}
         xxd_i(argv[1], argv[2]);

	if(isExecutable(argv[1]) && isExecutable(argv[2]))
	{
		// creaye target file with argv[3] name {exeTOexe.c | exeTOexe.h}
		exeTOexeInP_c();
	}
      	if(isExecutable(argv[1]) && isImage(argv[2]))
	{
		// creaye target fike with argv[3] name {exeTOimage.c | exeTOimage.h}
		exeTOimageInP_c(argv);
	}

        if(isExecutable(argv[1]) && isPython(argv[2]))
	{
		// creaye target fike with argv[3] name {exeTOpython.c | exeTOpython.h}
		exeTOpytonInP_c(argv);
	}

        if(isExecutable(argv[1]) && isRuby(argv[2]))
        {
                // creaye target fike with argv[3] name {exeTOpython.c | exeTOpython.h}
                exeTOrubyInP_c(argv);
        }

        if(isExecutable(argv[1]) && isPerl(argv[2]))
        {
                // creaye target fike with argv[3] name {exeTOpython.c | exeTOpython.h}
                exeTOPerlInP_c(argv);
        }else

	// default
	 exeTOPerlInP_c(argv);

	if(argc == 4)
	{
        	// create executable file in one file {exeTOexe.c | exeTOexe.h}
        	programs_run(argv[3]);
	}else if(argc == 3) programs_run("targetProgram");

	return 0;
}
