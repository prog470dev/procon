/*
2017_06_11_AC
<point>
・状態（ ステップ数, ゴミの取得状態, Y座標, X座標 ）で、ダイクストラを回す。
・ゴミの最大個数が１０個なので、ゴミの取得状態をbitで持てる。( 最大: (1<<10)-1 )
・ゴミの番号付けは、座標との対応でつける。
<caution>
・深さ優先探索だと微妙に間に合わない。（8.5sくらい）
・特定のビットを折りたいときは演算子 "&~" を使用する。
　例：i番目のビットを折りたいとき → "sate &~ (1<<i)"
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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int W,H,sy,sx,dustsNum;
string C[25];

int dp[25][25][1050];
map<pair<int,int>, int> m;

int main() {
  while(1){
      cin>>W>>H;
      if(W==0&&H==0) break;
      dustsNum=0;
      m.clear();
      REP(i,0,H){
        cin>>C[i];
        REP(j,0,W){
          if(C[i][j] == 'o') sy = i, sx = j;
          if(C[i][j] == '*'){
            m[make_pair(i,j)] = dustsNum;
            dustsNum++;
          }
        }
      }
      REP(i,0,H)REP(j,0,W){
        REP(k,0,(1<<dustsNum)){
          dp[i][j][k] = INF;
        }
      }

    priority_queue<pair< pair<int,int>, pair<int,int> > > PQ;  //step, state, Y, X
    PQ.push(make_pair(make_pair(0,(1<<dustsNum)-1), make_pair(sy, sx)));

    while(!PQ.empty()){
      int nowStep = (-1)*PQ.top().F.F;
      int nowState = PQ.top().F.S;
      int nowY =PQ.top().S.F, nowX = PQ.top().S.S;
      PQ.pop();

      if(dp[nowY][nowX][nowState] <= nowStep) continue;
      dp[nowY][nowX][nowState] = nowStep;

      REP(k,0,4){
        int nextY = nowY + dy[k], nextX = nowX + dx[k];
        if(!CK(nextY,0,H) || !CK(nextX,0,W)) continue;
        if(C[nextY][nextX] == 'x') continue;

        if(C[nextY][nextX] == '*'){
          int dust = m[make_pair(nextY,nextX)];
          PQ.push(make_pair(make_pair((-1)*(nowStep+1), nowState&~(1<<dust)), make_pair(nextY, nextX)));
        }else{
          PQ.push(make_pair(make_pair((-1)*(nowStep+1), nowState), make_pair(nextY, nextX)));
        }
      }
    }

    int ans = INF;
    REP(i,0,H)REP(j,0,W){
      ans = min(ans, dp[i][j][0]);
    }

    if(ans == INF) cout<<-1<<endl;
    else cout<<ans<<endl;
  }

  return 0;
}
