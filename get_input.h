#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 64
#define TOKEN_DELIMITERS " \t\r\n"

char* read_input(void);
char** tokenize_input(char*);
