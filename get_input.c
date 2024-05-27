#include "get_input.h"
#include "environment.h"

environment env;

static void print_prompt(void){
    printf(">" );
}

char* read_input(void){
	
	char *input = malloc(MAX_INPUT_SIZE);

    print_prompt();

	if(fgets(input, MAX_INPUT_SIZE, stdin) == NULL){
		free(input);
		return NULL;
	}
	else{
		input[strcspn(input, "\n")] = 0;
		return input;
	}	
	return input;
}

char** tokenize_input(char* input){

    int position = 0;
    char *token;
    char **tokens = malloc(MAX_TOKENS * sizeof(char*));

    if(!tokens){
        perror("tokens not initialized");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, TOKEN_DELIMITERS);
    while(token != NULL){
        tokens[position++] = token;
        token = strtok(NULL, TOKEN_DELIMITERS);
    }
    tokens[position] = NULL;
    return tokens;
}