#include <stdio.h>

void main()
{
    int i, ch, flag = 0;
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    do
    {
        printf("\n1.Encrypt String\n2.Decrypt String \n3.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
                if(flag == 1)  
                {
                     printf("\nAlready encrypted : %s\n", str);
                     break;
                }

                flag = 1;
                for (i = 0; (i < 100 && str[i] != '\0'); i++)
                {
                    str[i] = str[i] + 2;
                }

                printf("\nEncrypted String is : %s\n", str);
                break;

        case 2:
                if (flag)
                {
                    for (i = 0; (i < 100 && str[i] != '\0'); i++)
                    {
                        str[i] = str[i] - 2;
                    }

                    printf("\nDecrypted String is : %s\n", str);
                    flag = 0;
                }
                else{
                    printf("\nNot encrypted \n");
                }
                break;
                

        case 3:
                printf("\n\nExiting...\n\n");

        default:
                printf("\n\nInvalid choice");
        }

    } while (ch != 3);
}