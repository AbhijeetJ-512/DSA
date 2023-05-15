#include <stdio.h>

int find_gcd(int a, int b)
{
    int gcd = 0;
    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

void max_volume(int l, int b, int h)
{
    int cub_l = find_gcd(l, find_gcd(b, h));
    int num = l / cub_l;
    num = (num * b) / cub_l;
    num = (num * h) / cub_l;
    printf("It can form %d numbers of cubes with side length = %d", num, cub_l);
}

void main()
{
    int l, b, h;
    printf("Enter length breadth height of cuboid:\n");
    scanf("%d%d%d", &l, &b, &h);
    max_volume(l, b, h);
}