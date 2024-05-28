#include "stdlib.h"
#include <stdio.h>
#include <string.h>

#include "environment.h"

static int set_env_var(char* str, env_vars *variables);
static int resize_var_buffer(env_vars *variables);


environment* initialize_environment(void){
        environment *env = malloc(sizeof(*env));
        if(!env){
                perror("Environment memory allocation error");
                exit(EXIT_FAILURE);
        }

        env->variables.buffer = malloc(INITIAL_CAPACITY * sizeof(char*));
        if(!env->variables.buffer){
                perror("Environmental variable buffer memory allocation error");
                exit(EXIT_FAILURE);
        }
        env->variables.size = 0;
        env->variables.capacity = INITIAL_CAPACITY;
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


static int set_env_var(char* str, env_vars *variables){
        if(variables){
                for(unsigned int i = 0; i < variables->size; i++){
                        char *var = variables->buffer[i];
                        char *eq_sign = strchr(var, '=');
                        if(eq_sign){
                                size_t len = eq_sign - var;
                                if(len == strlen(str) && (!strncmp(var, str, len))){
                                                variables->buffer[i] = str;
                                                return 0;
                                }
                        }         
                }
                if(variables->size == variables->capacity){
                        if(resize_var_buffer(variables) == -1){
                                return -1;
                        }
                        variables->buffer[variables->size++] = str;
                        return 0;
                }
                else{
                        variables->buffer[variables->size++] = str;
                        return 0;  
                }
        }
        return -1;
}

static int resize_var_buffer(env_vars *variables){
        if(variables){
                variables->capacity *= 2;
                char ** temp = realloc(variables->buffer, variables->capacity * sizeof(char*));
                if(temp){
                        variables->buffer = temp;
                        return 0;
                }
                variables->capacity /= 2;
                return -1;
        }
        return -1;
}