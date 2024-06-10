#include "get_input.h"
#include "environment.h"


static char* input;
static char **tokens;
static environment* env;

int main(void){

    env = initialize_environment();

    while(1){
        if(input = read_input()){
            if(tokens = tokenize_input(input)){
            		free(tokens);   
            }
		free(input);   
        }
    }

    destroy_environment(env);
    return 0;
}
