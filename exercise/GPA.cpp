#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int score[] = {0,60,62,65,67,70,75,80,85,90,95,500};
int GPA[] = {0,10,17,20,23,27,30,33,37,40,43,-1000};

int dfs(int x, int step)
{
    if (step == 1)
    {
        if (x >= 95)
            return 43;
        if (x >= 90)
            return 40;
        if (x >= 85)
            return 37;
        if (x >= 80)
            return 33;
        if (x >= 75)
            return 30;
        if (x >= 70)
            return 27;
        if (x >= 67)
            return 23;
        if (x >= 65)
            return 20;
        if (x >= 62)
            return 17;
        if (x >= 60)
            return 10;
    }
    int ans = 0;
    for (int i = 1;score[i] <= x;i++)
    {
        ans = max(ans, GPA[i] + dfs(x - score[i], step--));
    }
    return ans;
}

int main()
{
    int x;
    scanf("%d", &x);
    while (x--)
    {
        int sco;
        scanf("%d", &sco);
        int ans = dfs(sco, 4);
        int a = ans / 10;
        int b = ans % 10;
        printf("%d.%d", a, b);
    }
    return 0;
}