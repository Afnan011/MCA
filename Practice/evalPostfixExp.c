#include<stdio.h>
#include<ctype.h>
#define MAX 20

void push(int);
int pop();

int stack[MAX];
int top = -1;

void main()
{
    char exp[20];
    char *op;
    int n1, n2, res;

    printf("\nEnter the postfix expression for evaluation: ");
    scanf("%s", exp);

    op = exp;
    while(*op != '\0')
    {

        if(isdigit(*op))
        {
            res = *op - 48;
            push(res);
        }
        else{
            n1 = pop();
            n2 = pop();

            switch(*op)
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

    printf("After evaluation of the postfix expression (%s) is = %d\n", exp, pop());


}


void push(int item)
{
    if(top == MAX-1)
    {
        printf("Stack full");
        return;
    }

    top++;
    stack[top] = item;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack empty");
        return -1;
    }

    int item = stack[top];
    top--;
    return item;
}
