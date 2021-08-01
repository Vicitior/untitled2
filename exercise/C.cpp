#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        long long int a, b, k, ansa, ansb;
        scanf("%lld%lld%lld", &a, &b, &k);
        if (k == 0)
        {
            ansa = a % 998244353;
            ansb = b % 998244353;
        }
        else if (k == 1)
        {
            ansa = (a + b) % 998244353;
            ansb = (a - b) % 998244353;
        }
        else if (k <= 100) {
            if (k % 2 == 0) {
                k = k / 2;
                ansa = (unsigned long long) pow(2, k) % 998244353 * a;
                ansb = (unsigned long long) pow(2, k) % 998244353 * b;
            } else {
                ansa = (k - 1) * (a + b) % 998244353;
                ansb = (k - 1) * (a - b) % 998244353;
            }
        }
        else
            {
            int p;
            ansa = 1;
            ansb = 1;
            while (k > 100) {
                k = k % 100;
                p = k / 100;
                ansa =(unsigned long long)pow(2, 50)*a  * p*ansa% 998244353;
                ansb =(unsigned long long)pow(2, 50) * b * p* ansb% 998244353;
            }
                if (k % 2 == 0) {
                    k = k / 2;
                    ansa = (long long int) pow(2, k) % 998244353 * a * ansa;
                    ansb = (long long int) pow(2, k) % 998244353 * b * ansb;
                } else {
                    ansa = (k - 1) * (a + b) % 998244353 * ansa;
                    ansb = (k - 1) * (a - b) % 998244353 * ansb;
                }
            }
        printf("%lld %lld\n", ansa, ansb);
    }
    return 0;
}