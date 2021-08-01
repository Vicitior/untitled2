#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int f[N][N];

int n, m;
int v[N], w[N];

int main()
{
    int i, j;
    scanf("%d%d", &n, &m);
    for (i =1;i <= n;i++)
    {
        scanf("%d%d", &v[i], w[i]);
    }
    for (i = 1;i <= n;i++)
    {
        for (j = 0;j <= n;j++)
        {
            f[i][j] = f[i - 1][j];
            if(j > v[i])
            {
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
            }
        }
    }
    printf("%d", f[n][m]);
    return 0;
}