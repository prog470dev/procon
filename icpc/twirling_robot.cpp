/*
2017_02_25_AC
＜ポイント＞
・同じマスでも、到達したときの「向き」で別扱いすること
・dfs()の最初でgrid[y][x]のときreturnしてしまうと、
　そのマスから命令して次のマスへ進むことができなくなってしまう。
＜疑問＞
・memset(dp, INF, sizeof(dp));で塗れない理由
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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

const int INF = 1000000000;
int w, h, cost[4], grid[35][35], dp[35][35][4];

void dfs(int y, int x, int dir, int currentcost){
  //goal4つの最低値より大きかったら枝刈り
  if(!CH(y,0,h) || !CH(x,0,w)) return;
  if(dp[y][x][dir] <= currentcost) return;
  dp[y][x][dir] = currentcost;
  if((x == w-1 && y == h-1)/* || grid[y][x] == 4*/) return;
  REP(k,0,5){
    if(k == 0){ //命令なし
      int d = grid[y][x];
      if(d == 4) continue;//grid[y][x]==4 (halt) は何もしない
      dfs(y + dy[(dir + d) % 4], x + dx[(dir + d) % 4], (dir + d) % 4, currentcost);
    }else{  //命令有り（tk: 0 ~ 3）、命令4(halt)は意味なし
      int tk = k - 1; //k=0を無命令に割り当てているため、調整する
      if(tk == grid[y][x]) continue;
      dfs(y + dy[(dir + tk) % 4], x + dx[(dir + tk) % 4], (dir + tk) % 4, currentcost + cost[tk]);
    }
  }
  return;
}

int main() {

  while(1){
    cin>>w>>h;
    if(w==0 && h==0) break;
    REP(i,0,h){
      REP(j,0,w){
        cin>>grid[i][j];
      }
    }
    REP(k,0,4) cin>>cost[k];
    //memset(dp, INF, sizeof(dp));
    REP(i,0,h)REP(j,0,w)REP(k,0,4) dp[i][j][k] = INF;

    dfs(0, 0, 0, 0);

    cout<<*min_element(dp[h-1][w-1], dp[h-1][w-1]+4)<<endl;
  }

  return 0;
}
