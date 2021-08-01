#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int f[N][N];

int v[N], w[N], s[N];

int main()
{
    int i, j, k, n, m;
    scanf("%d%d", &n, &m);
    for (i = 1;i <= n;i++)
    {
        scanf("%d%d%d", &v[i], &w[i], &s[i]);
    }
    for (i = 1;i <= n;i++)
    {
        for (j = 0;j <= m;j++)
        {
            for (k = 0;k <= s[i] && k * v[i] <= j;k++)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]]+ k * w[i]);
            }
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}