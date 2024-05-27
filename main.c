#include "get_input.h"
#include "environment.h"


static char* input;
static char **tokens;

int main(void){

    while(1){
        if(input = read_input()){
            tokens = tokenize_input(input);
        }   
    }
    
    return 0;
}