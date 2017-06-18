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

int H, W, S, U[35][35];
pair<int, int> dp[35][35][35][35];
//dp[y1][x1][y2][x2]: [(y1,x1),(y2,x2)]の 長方形の <最大グループ数, 予備力>
//dp[0][0][H-1][W-1]が答えになる

pair<int, int>
dfs(int y1, int x1, int y2, int x2){
  if(dp[y1][x1][y2][x2].F == -INF){
     return dp[y1][x1][y2][x2];
  }

  pair<int, int> ret = make_pair(0, 0);//0でいいのか?

  //垂直分割
  //切り込み位置をすべて試す。
  for(int cutx=x1; cutx<=x2; cutx++){
    pair<int, int> left = make_pair(0, 0);
    pair<int, int> right = make_pair(0, 0);
    for(int j=x1; j<=cutx; j++){
      for(int i=y1; i<=y2; i++){
        //再帰的探索により、leftに左半分の<大グループ数, 予備力>を入れる
      }
    }
    for(int j=cutx; j<=x2; j++){
      for(int i=y1; i<=y2; i++){

      }
    }

    //最大のleft + right を毎回更新する。

    /*
    ret.F = max(ret.F, dfs(y1,x1,y2,i).F + dfs(y1,i,y2,x2).F);
    ret.S = max(ret.S, max(dfs(y1,x1,y2,i).S , dfs(y1,i,y2,x2).S));
    */
  }


  //水平分割

  return dp[y1][x1][y2][x2] = ret;
}

int main() {
  while(1){
    cin>>H>>W>>S;
    if(H==0&&W==0&&S==0) break;
    REP(i,0,H){
      REP(j,0,W){
        cin>>U[i][j];
      }
    }

    REP(i,0,H){
      REP(j,0,W){
        REP(k,0,H){
          REP(l,0,W){
            dp[i][j][k][l] = -INF;
          }
        }
      }
    }

    cout<<dp[0][0][H-1][W-1]<<endl;
  }

  return 0;
}
