/*
sampleは通るがテストは通らない（2017_01_05）
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int dx[] = {1,1,0,-1,-1,0};
int dy[] = {1,0,-1,-1,0,1};

int t, n, sx, sy, ans;
bool visited[61][61];  //(a, b) -> visited[a+30][b+30]
bool obj[61][61];

int main() {
  while(1){
    cin>>t>>n;
    if(t==0 && n==0) break;
    REP(i,0,61)REP(j,0,61) obj[i][j] = false;
    REP(i, 0, n){
      int x, y;
      cin>>x>>y;
      obj[y+30][x+30] = true;
    }
    cin>>sx>>sy;

    REP(i,0,61)REP(j,0,61) visited[i][j] = false;
    ans = 0;

    queue<int> qx;
    queue<int> qy;
    queue<int> qt;

    qx.push(sx);
    qy.push(sy);
    qt.push(0);

    while(!qx.empty()){
      int x = qx.front();
      int y = qy.front();
      int turn = qt.front();
      qx.pop(); qy.pop(); qt.pop();

      if(turn > t)continue;
      visited[y+30][x+30] = true;
      ans++;

      REP(k,0,6){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(!CH(ny+30, 0, 61) || !CH(nx+30, 0, 61)) continue;
        if(!visited[ny+30][nx+30] && !obj[ny+30][nx+30]){
          visited[ny+30][nx+30] = true;
          qx.push(nx); qy.push(ny); qt.push(turn+1);
        }
      }
    }

    cout<<ans<<endl;

  }

  return 0;
}
