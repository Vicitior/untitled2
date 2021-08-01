#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int x;
    scanf("%d", &x);
    while (x--)
    {
        double p;
        scanf("%lf", &p);
        if (p > 1)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
    return 0;
}