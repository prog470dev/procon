/*
<point>
・d[y1][x1][y2][x2]: 長方形(y1,x1,y2,x2)を一つの街として見た場合の最大値
・内包している長方形について再帰的に探索する。
・予備力：分割可能な内包グループの中で、最小値のものを、全体の合計から引いたもの。
<caution>
・dfs()の返り値の初期値は、”極端な状態”を考えて値を入れる。
・条件”分割できるグループ数が、これまでより多い”で事前に分岐させなくても、
　pairのfirstとして持っておけば、優先的に選択基準にしてくれる。
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
int sum[35][35][35][35];
pair<int, int> dp[35][35][35][35];
//dp[y1][x1][y2][x2]: [(y1,x1),(y2,x2)]の 長方形の <最大グループ数, 予備力>
//dp[0][0][H-1][W-1]が答えになる

pair<int, int> dfs(int y1, int x1, int y2, int x2){
  if(dp[y1][x1][y2][x2].F != -INF){
     return dp[y1][x1][y2][x2];
  }

  //first: そもそも街全体を”１つのグループ”として見れば、必ずうまくいくという前提より1を入れる
  //second: 自分が一つのグループだった場合の「予備力」を入れておく
  pair<int, int> ret = make_pair(1, S-(sum[0][0][H-1][W-1]-sum[y1][x1][y2][x2]));

  //垂直分割
  for(int cutx=x1; cutx<x2; cutx++){
    int suml = sum[y1][x1][y2][cutx];
    int sumr = sum[y1][cutx+1][y2][x2];
    //分割したグループ単体で、すでに条件を満たしていなければアウト
    //(そのグループを停電させても供給オーバー)
    if(sum[0][0][H-1][W-1]-suml > S || sum[0][0][H-1][W-1]-sumr > S) continue;
    pair<int, int>  l = dfs(y1,x1,y2,cutx);
    pair<int, int>  r = dfs(y1,cutx+1,y2,x2);
    pair<int, int> tmp = make_pair(l.F+r.F, min(l.S,r.S));  //予備力は最低値で計算される
    ret = max(ret, tmp);  //F->Sの順で評価されるのでこれでOK
  }

  //水平分割
  for(int cuty=y1; cuty<y2; cuty++){
    int suml = sum[y1][x1][cuty][x2];
    int sumr = sum[cuty+1][x1][y2][x2];
    if(sum[0][0][H-1][W-1]-suml > S || sum[0][0][H-1][W-1]-sumr > S) continue;
    pair<int, int>  l = dfs(y1,x1,cuty,x2);
    pair<int, int>  r = dfs(cuty+1,x1,y2,x2);
    pair<int, int> tmp = make_pair(l.F+r.F, min(l.S,r.S));  
    ret = max(ret, tmp);
  }

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
    //各範囲の合計値を出しておく。
    REP(i,0,H){
      REP(j,0,W){
        REP(ranH,0,H-i)REP(ranW,0,W-j){
          int tmp = 0;
          REP(k,i,i+ranH+1){
            REP(l,j,j+ranW+1){
              tmp += U[k][l];
            }
          }
          sum[i][j][i+ranH][j+ranW] = tmp;
        }
      }
    }
    //初期化
    REP(i,0,H){
      REP(j,0,W){
        REP(k,0,H){
          REP(l,0,W){
            dp[i][j][k][l] = make_pair(-INF,-INF);
          }
        }
      }
    }

    pair<int, int> ans = dfs(0,0,H-1,W-1);
    cout<<ans.F<<" "<<ans.S<<endl;
  }

  return 0;
}
