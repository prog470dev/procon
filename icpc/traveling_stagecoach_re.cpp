/*
・dp[i][j]: チケット状態jのときの、"ノードiから終点ノードまでの"最小時間
・一度でもその状態いｎ到達すれば、２重ループの中で、
　最小値が設定されることが、保証されている。
　よって、でメモ用のｄｐ[][]配列が初期値でなければ、必ず最小値がすでに入っている。
・メモ用のｄｐ[][]配列をINFで初期化していたが、
　始点からの最短距離がINFやINF以上に成ることがあるため、
　未到達の状態場合は、-1で初期化しておく。
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
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second

using namespace std;

const double INF = 1e9;

int N, M, P, A, B;
double t[10], road[35][35], dp[35][(1<<8)];

double dfs(int nowNode, int ticketState){
  if(nowNode == B-1) return 0;
  if(ticketState == 0) return INF;
  if(dp[nowNode][ticketState] != -1.0) return dp[nowNode][ticketState];
  double ret = INF;
  /*ここでINFを入れてしまっているから、目的地に到達しなかった場合、
    必ずd[A-1][1<<N)-1]（dfs(A-1,(1<<N)-1)）にはINF以上の数が入っていることが保証されている。*/
  REP(nextNode, 0, M){
    if(road[nowNode][nextNode] == INF) continue;
    REP(ticket, 0, N){
      if(!(ticketState & (1<<ticket))) continue;
      ret = min(ret, dfs(nextNode, ticketState^(1<<ticket) ) + road[nowNode][nextNode]/t[ticket] );
    }
  }
  return dp[nowNode][ticketState] = ret;
}

int main() {
  while(1){
    cin>>N>>M>>P>>A>>B;
    if(N==0) break;
    REP(i,0,N) cin>>t[i];
    REP(i,0,M)REP(j,0,M) road[i][j] = INF;
    REP(i,0,P){
      int x, y;
      double z;
      cin>>x>>y>>z;
      x--; y--;
      road[x][y] = road[y][x] = z;
    }
    REP(i,0,M)REP(j,0,(1<<N)) dp[i][j] = -1.0;
    double ans = dfs(A-1,(1<<N)-1);
    if(ans < INF) printf("%.5lf\n", ans);
    else cout<<"Impossible"<<endl;
    REP(i,0,M){
      REP(j,0,(1<<N)){
        cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
