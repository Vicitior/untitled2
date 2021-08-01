#include <stdio.h>
#include <iostream>
#include <algorithm>
#define N 10

using namespace std;

char a[N][N], n;
bool b[N], c[N], d[N];

void dfs(int k){
    if (k == n){
        for (int i = 0;i < n;i++){
            printf("%s", a[i]);
            printf("\n");
        }
        printf("\n");
        return;
    }
    else {
        for (int i = 0;i < n;i++){
            if (!b[i] && !c[i + k] && !d[n - k + i]){
                a[k][i] = 'Q';
                b[i] = c[i + k] = d[n - k + i] =true;
                dfs(k + 1);
                a[k][i] = '.';
                b[i] = c[i + k] = d[n - k + i] =false;
            }
        }
    }
}

int main(){
  scanf("%d", &n);
  for (int i = 0;i < n;i++){
      for (int j = 0;j < n;j++){
          a[i][j] = '.';
      }
  }
  dfs(0);
  return 0;
}