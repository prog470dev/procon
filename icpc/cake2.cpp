/*
2017_04_01_AC
<point>
・すでに取られた領域からつなげて広げていかなければならないため、
　状態は範囲 [sta, end]の数しかない。
　=> DP[sta][end]:ケーキのピースが、staからendまで取られているときのJOIの取りうる最大得点
・IOIは自動的に取るピースが決まっているため、
　どちらのターン化によって処理を分岐させてやる必要がある。
・どちらのターンであるかの判定は、残りピース数ではなく、
　dfs関数の引数として与えてやる方が確実。
<caution>
・減算だけでなく、加算においてもMODで調整する必要がある。
・範囲の基準を「残ってる方」のインデックスにしていたので、
　取得するピースのインデックスの指定が、ずれないように注意する。
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

long long dp[2005][2005];
int n, a[2005];

long long dfs(int sta, int end, int left, bool joi){
  if(dp[sta][end] != -1) return dp[sta][end];

  if(left == 1){
    if(!joi) {
      return dp[sta][end] = 0;
    }else{
      return dp[sta][end] = a[sta];
    }
  }

  if(!joi){
    if(a[sta] < a[end]){
      return dp[sta][end] = dfs(sta, (end+1)%n, left-1, true);
    }else{
      return dp[sta][end] = dfs((sta-1+n)%n, end, left-1, true);
    }
  }else{
    return dp[sta][end] = max(dfs((sta-1+n)%n, end, left-1, false) + a[sta], dfs(sta, (end+1)%n, left-1, false) + a[end]);
  }

}

int main() {
  cin>>n;
  REP(i,0,n) cin>>a[i];
  REP(i,0,n)REP(j,0,n) dp[i][j] = -1;
  vector<long long> v;
  REP(i,0,n) v.push_back( dfs(i,(i+1)%n,n,true) );
  cout<<*max_element(v.begin(), v.end())<<endl;
  return 0;
}
