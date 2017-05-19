/*
2017_04_20_AC
<Point>
・すでに訪れたステージをビットで管理
・dp[i]: すでに訪れたステージの状態 i の最小コスト
　→　dp[(1<<N)-1] が最終の答え（すべて訪れた状態）
<Caution>
・入力 t[][] の列数は N よりひとつ多い。
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

using namespace std;

int dp[(1<<17)], INF = 100000000;

int main() {
  while(1){
    int N, t[20][20];
    cin>>N;
    if(N==0) break;
    REP(i,0,N){
      REP(j,0,N+1){
        cin>>t[i][j];
      }
    }

    REP(i,0,(1<<N)){
      dp[i] = INF;
    }
    dp[0] = 0;

    REP(mask,0,(1<<N)){
      int minCost[16];
      //Calculate current minimum cost of each stage
      REP(i,0,N){
        minCost[i] = t[i][0];
        REP(j,0,N){
          if(i == j) continue;
          if(mask & (1<<j)) minCost[i] = min(minCost[i],t[i][j+1]);
        }
      }
      //Determination of the next stage
      REP(i,0,N){
        if(mask & (1<<i)) continue;
        dp[mask | (1<<i)] = min(dp[mask | (1<<i)], dp[mask] + minCost[i]);
      }
    }
    cout<<dp[(1<<N)-1]<<endl;
  }

  return 0;
}
