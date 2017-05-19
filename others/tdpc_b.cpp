/*
2017_01_11
・メモ化再帰で解いた。深さ優先探索で一度考えた残り個数の状況は記憶しておくイメージ。
・dp[i][j] : Aの山がi個、Bの山がj個残っているときの、先手の最大得点。
・入力のとく、残り個数とインデックスが逆順になるので注意
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int A,B,a[1005],b[1005],sum=0,dp[1005][1005];

int dfs(int an, int bn, int n){
  int ret;
  if(dp[an][bn] != -1) return dp[an][bn];
  if(n % 2 == sum % 2){ //先手
    if(an == 0){
      ret = dfs(an, bn-1, n-1) + b[bn];
    }else if(bn == 0){ //後手
      ret = dfs(an-1, bn, n-1) + a[an];
    }else{
      ret = max(dfs(an-1,bn,n-1) + a[an], dfs(an,bn-1,n-1) + b[bn]);
    }
  }else{
    if(an == 0){
      ret = dfs(an, bn-1, n-1);
    }else if(bn == 0){
      ret = dfs(an-1, bn, n-1);
    }else{
      ret = min(dfs(an-1,bn,n-1), dfs(an,bn-1,n-1));
    }
  }
  return dp[an][bn] = ret;
}

int main() {

  cin>>A>>B;
  sum = A + B;
  for(int i=0; i<A; i++) cin>>a[A-i];
  for(int i=0; i<B; i++) cin>>b[B-i];

  for(int i=0; i<=A; i++){
    for(int j=0; j<=B; j++){
        dp[i][j] = -1;
    }
  }

  dp[0][0] = 0;

  cout<<dfs(A,B,sum)<<endl;

  return 0;
}
