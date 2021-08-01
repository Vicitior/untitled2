#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

void dix(int x)
{
    for (int i = 2;i <= x / i;i++)
    {
        if (x % i ==0)
        {
            int n = 0;
            while (x % i == 0)
            {
                n++;
                x = x / i;
            }
            printf("%d %d\n", i, n);
        }
    }
    if (x > 1)
        printf("%d 1\n", x);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        dix(x);
    }
    return 0;
}