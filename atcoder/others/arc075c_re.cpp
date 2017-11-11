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

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long;

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;
long long N, S[105];

bool dp[110][10010];  //dp[i][j]:数字を i"個" 選ぶとき、j は作れるか？

int main() {
  cin>>N;
  long long sumd = 0, sum = 0;
  REP(i,0,N){
    cin>>S[i];
  }

  dp[0][0] = true;

  REP(i,0,N){
    REP(j,0,10010-S[i]){
      if(dp[i][j]){
        dp[i+1][j] = true;
        dp[i+1][j+S[i]] = true;
      }
    }
  }

  int ans = 0;
  REP(i,0,N+1){
    REP(j,0,10010){
      if(dp[i][j] && j%10 != 0){
        ans = max(ans, j);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
