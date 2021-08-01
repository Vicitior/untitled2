#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int a[N];

int main()
{
    int n, q, i;
    scanf("%d%d", &n, &q);
    for (i = 0;i < n;i++)
    {
        scanf("%d", &a[i]);
    }
    while (q--)
    {
        int x;
        scanf("%d", &x);
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (a[l] != x)
        {
            printf("-1 -1\n");
        }
        else {
            printf("%d ", l);
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (a[mid] <= x) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            printf("%d\n", l);
        }
    }
    return 0;
}