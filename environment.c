#include "stdlib.h"
#include <stdio.h>

#include "environment.h"

static int set_env_var(const char* str, env_vars *variables);
static int resize_var_buffer(char **buffer);


environment* initialize_environment(void){
        environment *env = malloc(sizeof(*env));
        if(!env){
                perror("environment.h line 11 malloc error");
                exit(EXIT_FAILURE);
        }

        env->variables.buffer = malloc(INITIAL_CAPACITY * sizeof(char*));
        if(!env->variables.buffer){
                perror("environment.h line 17 malloc error");
                exit(EXIT_FAILURE);
        }
        return env;
}


void destroy_environment(environment* env){
        if(env){
                for(unsigned int i = 0; i < env->variables.size; i++){
                        free(env->variables.buffer[i]);
                }
                free(env->variables.buffer);
                free(env);
        }
}