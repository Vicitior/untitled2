#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int a[N], b[N] , ans;

int main()
{
    int x;
    scanf("%d", &x);
    while (x--)
    {
        int n, m, w;
        scanf("%d%d", &n, &m);
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d", &a[i], &b[i]);
            if (m % a[i] == 0)
            {
                w = m / a[i];
            } else{
                w = m / a[i] + 1;
            }
            if (i == 1)
            {
                ans = w * b[i];
            } else{
                ans = min(ans, w * b[i]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}