#include<stdio.h>
#include<ctype.h>
#define MAX 20

int prec(char);
void push(char);
char pop();

char stack[MAX];
int top = -1;

void main()
{
    char exp[30];
    char *e, item;

    printf("Enter the infix expression: ");
    scanf("%s", exp);

    e = exp;

    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            printf("%c", *e);
        }

        else if(*e == '(')
        {
            push(*e);
        }

        else if(*e == ')')
        {
            while ( (item = pop()) != '(')
            {
                printf("%c", item);
            }
        }

        else
        {
            while ( prec(stack[top]) >= prec(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        
        e = e + 1;
    }

    while (top != -1)
    {
        printf("%c", pop());
    }
    
}


int prec(char op)
{
    if (op == '^')
        return 3;

    else if(op == '*' || op == '/')
        return 2;
    
    else if(op == '+' || op == '-')
        return 1;
    
    else
        return 0;
}

void push(char item)
{
    if (top == MAX - 1)
    {
        printf("Stack is full.");
        return;
    }

    top = top + 1;
    stack[top] = item;   
}

char pop()
{
    if (top == -1)
    {
        printf("Stack is empty");
        return -1;
    }

    char item = stack[top];
    top = top - 1;
    return item;  
}
