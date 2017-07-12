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
#include <deque>
#include <algorithm>

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long  LLINF = 1e18;

using namespace std;


int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int H,W,N,sy,sx;
string field[1010];

int main(){
  cin>>H>>W>>N;
  REP(i,0,H){
    cin>>field[i];
    REP(j,0,W){
      if(field[i][j]=='S') sy = i, sx = j;
    }
  }

  int ans = 0;

  REP(nowGoal,1,N+1){
    queue< pair< int, pair<int,int> > > q;
    bool visited[1010][1010];
    REP(i,0,H)REP(j,0,W) visited[i][j] = false;
    q.push(make_pair(0,make_pair(sy,sx)));

    while(!q.empty()){
      int nowStep = q.front().F;
      int nowy = q.front().S.F;
      int nowx = q.front().S.S;
      q.pop();
      if(field[nowy][nowx]-'0' == nowGoal){
        ans += nowStep;
        sy = nowy, sx = nowx;
        break;
      }
      if(visited[nowy][nowx]) continue;
      visited[nowy][nowx] = true;
      REP(k,0,4){
        int ny = nowy + dy[k];
        int nx = nowx + dx[k];
        if(!CK(ny,0,H) || !CK(nx,0,W)) continue;
        if(visited[ny][nx] || field[ny][nx]=='X') continue;
        q.push(make_pair(nowStep+1,make_pair(ny,nx)));
      }
    }
  }

  cout<<ans<<endl;

  return 0;
}
