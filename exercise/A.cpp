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
        long long int a, b, mina, maxa;
        scanf("%lld%lld", &a, &b);
        mina = 0;
        maxa = 0;
        if (a == 1&&b!=1 || b == 1&&a!=1)
        {
            if (a==b)
                break;

            maxa = max(a, b) - 1;
            if (maxa <=1)
                maxa = -1;
            if (max(a, b)%2!=0)
                mina = 2;
            else
                for (int i = 3;i<=max(a,b);i=i+2)
                {
                    if (max(a, b)%i==1)
                    {
                        mina=i;
                        break;
                    }
                }
                if (mina==0)
                {
                    mina=maxa;
                }
        }
        else {
            if (a == b) {
                if (a!=1) {
                    maxa = a;
                    mina = 2;
                }
                else{
                    maxa = -1;
                    mina = -1;
                }
            }
            else {
                if (a - b > 1 || b - a > 1) {
                    maxa = max(a - b, b - a);
                } else {
                    maxa = -1;
                    mina = -1;
                }
                if (mina != -1)
                    if (a%2==0&&b%2==0||a%2!=0&&b%2!=0)
                    {
                        mina = 2;
                    }
                else {
                        while (1) {
                            int q = max(a, b);
                            int p = min(a, b);
                            int m = q % p;
                            if (m == 0) {
                                mina = p;
                                break;
                            }
                            if (m == 1) {
                                mina = maxa;
                                break;
                            }
                            a = p;
                            b = m;
                        }
                    }
                for (int i = 2;i<=sqrt(mina);i++)
                {
                    if (mina%i==0) {
                        mina = i;
                        break;
                    }
                }
            }
        }
        printf("%lld %lld\n", mina, maxa);
    }
    return 0;
}
