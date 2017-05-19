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

int dx[] = {1,1,0,-1,-1,0};
int dy[] = {1,0,-1,-1,0,1};

int t, n, sx, sy, ans, diff = 200;
bool visited[300][300][31];  //(a, b) -> visited[a+30][b+30]
bool obj[300][300];

void dfs(int y, int x, int turn){
  if(visited[y+diff][x+diff][turn]) return;
  if(turn > t) return;

  bool flag = true;
  REP(i,0,31){
    if(visited[y+diff][x+diff][i]) flag = false;  /*来たことがある*/
  }
  if(flag) ans++;

  visited[y+diff][x+diff][turn] = true;

  REP(k,0,6){
    int nx = x + dx[k], ny = y + dy[k];
    //if(!CH(ny+100, 0, 61) || !CH(nx+100, 0, 61)) continue;
    if(obj[ny+diff][nx+diff]) continue;
    dfs(ny, nx, turn + 1);
  }
  return;
}

int main() {
  //test
  //vector<int> v;

  while(1){
    cin>>t>>n;
    if(t==0 && n==0) break;
    REP(i,0,300)REP(j,0,300) obj[i][j] = false;
    REP(i, 0, n){
      int x, y;
      cin>>x>>y;
      obj[y+diff][x+diff] = true;
    }
    cin>>sx>>sy;

    REP(i,0,300)REP(j,0,300)REP(k,0,31) visited[i][j][k] = false;
    ans = 0;

    dfs(sy, sx, 0);

    cout<<ans<<endl;
    //v.push_back(ans);
  }

  //REP(i,0,v.size()) cout<<v[i]<<" ";
  //cout<<endl;

  return 0;
}
