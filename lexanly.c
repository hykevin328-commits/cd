
#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i = 0, j;

    printf("enter the input string\n");
    fgets(str, sizeof(str), stdin);

    while(str[i] != '\0')
    {
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            i++;
            continue;
        }

        if(isalpha(str[i]) || str[i] == '_')
        {
            char identifer[50];
            int j = 0;

            while(isalnum(str[i]) || str[i] == '_')
            {
                identifer[j++] = str[i++];
            }

            identifer[j] = '\0';

            printf("identifer: %s\n", identifer);
        }
        else if(isdigit(str[i]) || str[i] == '_')
        {
            char number[50];
            int j = 0;

            while(isdigit(str[i]) || str[i] == '_')
            {
                number[j++] = str[i++];
            }

            number[j] = '\0';

            printf("number: %s\n", number);
        }
        else
        {
            printf("operator %c\n", str[i]);
            i++;
        }
    }

    return 0;
}
