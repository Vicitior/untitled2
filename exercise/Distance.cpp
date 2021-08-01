#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 100010;
long long int a[N];

int main()
{
    int x;
    scanf("%d", &x);
    while (x--)
    {
        int n;
        long long int b = 0;
        scanf("%d", &n);
        for (int i = 1;i <= n;i++)
        {
            scanf("%lld", &a[i]);
        }
        sort(a + 1, a + n + 1);
        for (int i = 1;i <= n;i++)
        {
            b += (a[i + 1] - a[i]) * (n - i) * i;
        }
        printf("%lld\n", b);
    }
    return 0;
}