#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int x;
    scanf("%d", &x);
    while (x--)
    {
        int num = 0, n, m, p;
        double q;
        scanf("%d%d%d", &n, &m, &p);
        q = (double)(m * p) / 100;
        if (n >= m) {
            if (p == 100)
                num = n / q;
            else {
                num = n / q;
                if (n - (num - 1) * q < m)
                    num--;
            }
            printf("%d\n", num);
        } else
            printf("0\n");
    }
    return 0;
}