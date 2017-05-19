#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int main() {

  int n;
  long long a[100005], dp[100005];
  cin>>n;
  long long  sum = 0;
  REP(i,0,n){
    cin>>a[i];
    sum += a[i];
    dp[i] = sum;
  }

  long long diff = 0, ans = 0;
/*
  if(dp[0] == 0){
    if(dp[1] < 0) diff++, ans++;
    else diff--, ans++;
  }
  */
  if(dp[0] == 0){
    ans++;
    diff++;
  }
  REP(i,1,n){
    if(dp[i] + diff == 0){
      if(dp[i-1] + diff < 0) diff++, ans++;
      if(dp[i-1] + diff > 0) diff--, ans++;
      continue;
    }
    if((dp[i-1] + diff)/llabs(dp[i-1] + diff) == (dp[i] + diff)/llabs(dp[i] + diff)){
      if(dp[i] + diff < 0){
        ans += llabs(dp[i] + diff) + 1;
        diff += llabs(dp[i] + diff) + 1;
      }else{
        ans += llabs(dp[i] + diff) + 1;
        diff -= llabs(dp[i] + diff) + 1;
      }
    }
  }

  long long tans = ans;
  diff = 0; ans = 0;
  if(dp[0] == 0){
    ans++;
    diff--;
  }else{
    ans += llabs(dp[0]) + 1;
    if(dp[0] > 0) diff -= llabs(dp[0]) + 1;
    else diff += llabs(dp[0]) + 1;
  }
  REP(i,1,n){
    if(dp[i] + diff == 0){
      if(dp[i-1] + diff < 0) diff++, ans++;
      if(dp[i-1] + diff > 0) diff--, ans++;
      continue;
    }
    if((dp[i-1] + diff)/llabs(dp[i-1] + diff) == (dp[i] + diff)/llabs(dp[i] + diff)){
      if(dp[i] + diff < 0){
        ans += llabs(dp[i] + diff) + 1;
        diff += llabs(dp[i] + diff) + 1;
      }else{
        ans += llabs(dp[i] + diff) + 1;
        diff -= llabs(dp[i] + diff) + 1;
      }
    }
  }

  cout<<min(ans, tans)<<endl;

  return 0;
}
