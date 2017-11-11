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

int N, M, a, b, ans = 0;
bool graph[9][9], visit[9];

void dfs(int node){
  int cnt = 0;
  REP(i,1,N+1) if(visit[i]) cnt++;
  if(cnt == N-1){
    ans++;
    return;
  }
  if(visit[node]) return;
  visit[node] = true;
  REP(i,1,N+1){
    if(graph[node][i] && !visit[i]) dfs(i);
  }
  visit[node] = false;
  return;
}

int main() {

  REP(i,0,N+1)REP(j,0,N+1) graph[i][j] = false;
  REP(i,0,N+1) visit[i] = false;

  cin>>N>>M;
  REP(i,0,M){
    cin>>a>>b;
    graph[a][b] = true;
    graph[b][a] = true;
  }

  dfs(1);
  cout<<ans<<endl;

  return 0;
}
