#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#define INITIAL_CAPACITY 4


typedef struct{
    char **buffer;
    size_t size;
    size_t capacity;
}env_vars;

typedef struct{
    env_vars variables;
    char *prompt_conf;
    char *history;
}environment;


/*API*/

environment* initialize_environment(void);
void         destroy_environment(environment*);
#endif

