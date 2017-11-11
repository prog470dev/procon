/*
・N<=30の場合の解法で、最後の組み合わせを見つける部分の実装が、愚直なので、
　二部探索など、別の方法を見つけるべき。
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
#include <stack>
#include <queue>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(long long i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int N, W, v[205], w[205];
long long dp[205][200*1005], vdp[205][200*1005];
long long INF = 1<<30;

long long func1(){
  vector< pair<long long, long long> > v1, v2;

  //v1.push_back(make_pair(0,0));
  int lim = min(N,15);
  REP(mask,0,(1<<lim)){
    long long wsum = 0, vsum = 0;
    REP(i,0,lim){
      if(mask & (1<<i)) wsum += w[i], vsum += v[i];
    }
    if(wsum <= W) v1.push_back(make_pair(wsum, vsum));
  }


  v2.push_back(make_pair(0,0));
  lim = max(0,N-15);
  REP(mask,0,(1<<lim)){
    long long wsum = 0, vsum = 0;
    REP(i,0,lim){
      if(mask & 1<<i) wsum += w[i+15], vsum += v[i+15];
    }
    if(wsum <= W) v2.push_back(make_pair(wsum, vsum));
  }

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  long long ret = 0;
  //ここで2^15 * 2^15..... → 二分探索
  REP(i,0,v1.size()){
    REP(j,0,v2.size()){
      if(v1[i].first + v2[j].first <= W) ret = max(ret, v1[i].second + v2[j].second);
    }
  }
  return ret;
}

long long func2(){
  REP(i,0,W) dp[0][i] = 0;
  REP(i,0,N) dp[i][0] = 0;
  REP(i,1,N+1){
    REP(j,1,W+1){
      if(0 <= j - w[i-1]) dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i-1]] + v[i-1]);
      else dp[i][j] = dp[i-1][j];
    }
  }
  return dp[N][W];
}

long long func3(){
  REP(i,0,200*1005) vdp[0][i] = INF;
  REP(i,0,N) vdp[i][0] = 0;
  REP(i,1,N+1){
    REP(j,1,200*1005){
      if(0 <= j - v[i-1]) vdp[i][j] = min(vdp[i-1][j], vdp[i-1][j - v[i-1]] + w[i-1]);
      else vdp[i][j] = vdp[i-1][j];
    }
  }

  int ret = 0;
  REP(i,0,200*1005){
    if(vdp[N][i] <= W) ret = i;
  }
  return ret;
}

int main() {

  cin>>N>>W;
  int mw = 0;
  REP(i,0,N){
    cin>>v[i]>>w[i];
    mw = max(mw, w[i]);
  }

  if(N <= 30) cout<<func1()<<endl;
  else if(mw <= 1000) cout<<func2()<<endl;
  else cout<<func3()<<endl;

  return 0;
}
