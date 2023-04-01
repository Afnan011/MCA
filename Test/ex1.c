#include <stdio.h>
#include <string.h>
#define MAX_STACK 20

char stack[MAX_STACK];
int top = -1;

void main()
{
    char infix[MAX_STACK], postfix[MAX_STACK];

    strcpy(infix, "A+B");

    int j = 0;
    char *exp;
    exp = infix;

   while(*exp != '\0')
    {

        printf("%c",*exp);
        postfix[j++] = *exp;

        exp = exp + 1;
    }

    postfix[j] = '\0';

    printf("\npostfix : %s", postfix);
}