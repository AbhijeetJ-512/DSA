#include <stdio.h>
#include <time.h>

char generate()
{
    char str1[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char str2[26] = "qwertyuioplkjhgfdsazxcvbnm";
    char spec[10] = "!@#$%^&*()+";
    char num[10] = "0123456789";
    int x, y;
    char c;
    x = rand() % 4;
    switch (x)
    {
    case 0:
        y = rand() % 26;
        c = str1[y];
        return c;
    case 1:
        y = rand() % 26;
        c = str2[y];
        return c;
    case 2:
        y = rand() % 10;
        c = spec[y];
        return c;
    case 3:
        y = rand() % 10;
        c = num[y];
        return c;
    }
}

void main()
{

    printf("Enter how many charcter password u want:\n");
    int n;
    srand(time(NULL));
    scanf("%d", &n);
    char pass[n];
    for (int i = 0; i < n; i++)
    {
        pass[i] = generate();
        printf("%c", pass[i]);
    }
}