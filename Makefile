PRO_NAME = IAInjectioner
LIBS = -lpthread
CFILE = *.c
CC = gcc
OPT = -w -g -Wall

all:
	$(CC) $(OPT) -o $(PRO_NAME) $(CFILE) $(LIBS)
