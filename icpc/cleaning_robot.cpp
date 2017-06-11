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

void dfs(int y, int x, int state, int step){
  if(dp[y][x][state] <= step) return;
  dp[y][x][state] = step;

  if(state == 0) return;

  REP(k,0,4){
    int nextY = y + dy[k], nextX = x + dx[k];
    if(!CK(nextY,0,H) || !CK(nextX,0,W)) continue;
    if(C[nextY][nextX] == 'x') continue;

    if(C[nextY][nextX] == '*'){
      int dust = m[make_pair(nextY,nextX)];
      dfs(nextY, nextX, state&~(1<<dust), step+1);
    }else{
      dfs(nextY, nextX, state, step+1);
    }

  }
}

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

      dfs(sy, sx, (1<<dustsNum)-1, 0);

      int ans = INF;
      REP(i,0,H)REP(j,0,W){
        ans = min(ans, dp[i][j][0]);
      }

      if(ans == INF) cout<<-1<<endl;
      else cout<<ans<<endl;
  }


  return 0;
}
