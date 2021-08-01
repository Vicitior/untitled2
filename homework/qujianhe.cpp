#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 300010;

typedef pair<int,int> PII;

int a[N], s[N];

vector<int>alls;
vector<PII>add, query;

int find (int x)
{
    int l = 0;
    int r = alls.size() - 1;
    while (l < r) {
        int mid = (r + l) / 2;
        if (alls[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r + 1;
}

int main()
{
    int n, m, x, c, l, r;
    scanf("%d%d", &n, &m);
    while(n--)
    {
        scanf("%d%d", &x, &c);
        add.push_back({x, c});
        alls.push_back(x);
    }
    while(m--)
    {
        scanf("%d%d", &l, &r);
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for(auto itdm : add)
    {
        int x;
        x = find(itdm.first);
        a[x] += itdm.second;
    }
    for (int i = 1;i <= alls.size();i++)
    {
        s[i] = s[i - 1] + a[i];
    }
    for(auto itdm : query)
    {
        l = find(itdm.first);
        r = find(itdm.second);
        printf("%d\n",s[r] - s[l - 1]);
    }
    return 0;
}