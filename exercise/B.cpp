//
// Created by Vicit on 2021/7/31.
//

#include<iostream>
typedef long long LL;
using namespace std;
LL max(LL a,LL b){
    return a>b?a:b;
}
LL min(LL a,LL b){
    return a<b?a:b;
}
int main(){
    //freopen("in.txt","r",stdin);
    int T;
    LL a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&a,&b);
        LL maxc=max(a,b);
        LL maxA=-1,minA=-1;
        int i=2;
        while(i<=maxc){
            if(a%i==b%i){
                minA=i;
                break;
            }
            i++;
        }
maxA = max(a,b)-min(a,b);
        printf("%lld %lld\n",minA,maxA);
    }
}
