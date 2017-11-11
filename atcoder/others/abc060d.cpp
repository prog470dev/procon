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

int INF = 1000000005;

int main() {

  int N, W, w[105], v[105];
  int minw = INF;
  cin>>N>>W;
  REP(i,0,N){
    cin>>w[i]>>v[i];
    minw = min(minw, w[i]);
  }

  long long dp[105][310];
  REP(i,0,105)REP(j,0,310) dp[i][j] = 0;

  REP(i,1,N+1){
    REP(j,0,min((W-minw)+2, 310)/*310*/){
      //if(j < w[i-1]-minw+1) continue;
      long long  tmp = (j+(long long)minw-1)-(long long)w[i-1], ind;

      if(0 <= tmp && tmp < minw) ind = 0;
      else if(minw <= tmp) ind = j - w[i-1] /*(j+minw-1) - w[i-1]-1*/;
      else ind = -1;

      //test
      /*
      if(i==1 && j == 0){
        cout<<"tmp: "<<tmp<<", ind: "<<ind<<endl;
      }
      */

      if(0 <= ind && ind < 310/* && j >= w[i-1]-minw+1*/) dp[i][j] = max(dp[i-1][j], dp[i-1][ind] + v[i-1]);
      else dp[i][j] = dp[i-1][j];
    }
  }

  if(W-minw+1 < 0 || W-minw+1 >= 310) cout<<dp[N][309]<<endl;
  else cout<<dp[N][W-minw+1]<<endl;

  return 0;
}
