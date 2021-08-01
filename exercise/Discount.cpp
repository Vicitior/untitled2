#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int b[N];
double c[N];

int main() {
    int x;
    scanf("%d", &x);
    while (x--) {
        int n;
        double ans = 0;
        scanf("%d", &n);
        for (int i = 1;i <= n; i++) {
            scanf("%d%lf", &b[i], &c[i]);
            ans = max(ans, (1 - c[i]) / (b[i] + 1 - c[i]));
        }
        printf("%.5f\n", ans);
    }
    return 0;
}