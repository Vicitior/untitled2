#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int a[N], s[N];

int main()
{
    int n, m, l, r, i;
    scanf("%d%d", &n, &m);
    for (i = 1;i <= n;i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i -1] + a[i];
    }
    while (m--)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}