#include <stdio.h>

int str_length(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void main()
{
    char str[100];
    printf("Enter string:\n");
    gets(str);
    int n = str_length(str);
    printf("Length of string=%d", n);
}