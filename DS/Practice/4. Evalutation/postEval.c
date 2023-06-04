#include<stdio.h>
#include<ctype.h>
#define MAX 20

void push(int);
int pop();

int stack[MAX];
int top = -1;

void main()
{
    char exp[20], *op;
    int n1, n2, res;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    op = exp;
    while (*op != '\0')
    {
        if (isdigit(*op))
        {
            res = *op - 48;
            push(res);
        }

        else
        {
            n1 = pop();
            n2 = pop();

            switch (*op)
            {
            case '+': res = n2 + n1;
                      break;
            case '-': res = n2 - n1;
                      break;   
            case '*': res = n2 * n1;
                      break;
            case '/': res = n2 / n1;
                      break;                                  
            }

            push(res);
        }
        op = op + 1;
    }
    
    printf("\nAfter evaluation of the postfix expression %s : ", exp);
    printf("\nThe result is = %d", pop());

}

void push(int item)
{
    if (top == MAX-1)
        return;

    top++;
    stack[top] = item;
}

int pop()
{
    if (top == -1)
        return -1;

    int item = stack[top];
    top--;

    return item;  
}