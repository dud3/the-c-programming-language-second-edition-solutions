#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000

int stack[MAX];
int top = 0;

void push(int value);
int pop(void);

int main(int argc, char *argv[])
{
    /* 0 = success; -1 = fail */
    int error = 0;
    
    /* Increment input, skip the program name */
    argc--;
    argv++;
  
    if(argc == 0) {
        printf("expr: illegal options.");
        return -1;
    }
    
    double op2;
    
    int i;
    for(i = 0; i < argc; i++) {
        
        char *p;
        int argvd = strtol(*argv, &p, 10);
        
        if(argvd > 0) {
            /* Error handling here... */
            
            /* Push the int */
            push(argvd);
        } else {
            switch (*argv[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                    
                case 'x':
                    push(pop() * pop());
                    break;
                
                case '-':
                    push(pop() - pop());
                    break;
                    
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    break;
                
                default:
                    error = -1;
                    break;
            }
        }
        
        /* Increment the memory address to the next block */
        ++argv;
    }
    
    if(error == -1) {
        /* Program failed... */
    }
    
    printf("last: %d \n", pop());

    return 0;
}

void push(int value)
{
    /* Error handling later on... */
    stack[top++] = value;
}

int pop(void)
{
    if (top > 0) {
        int ret = stack[--top];
        return ret;
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}