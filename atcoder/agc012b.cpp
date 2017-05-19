#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int N, M, Q, a, b, c[2005], v[2005], d[2005];

int graph[2005][2005];
int node[2005];

int main() {

  cin>>N>>M;
  if(N>2000 || M>2000) return 0;

  REP(i,0,N)REP(j,0,N) graph[i][j] = 100000000;
  REP(i,0,N) node[i] = 0;

  REP(i,0,M){
    cin>>a>>b;
    graph[a-1][b-1] = 1;
    graph[b-1][a-1] = 1;
  }
  cin>>Q;
  if(Q>2000) return 0;
  REP(i,0,Q) cin>>v[i]>>d[i]>>c[i];

  REP(k,0,N){
    REP(i,0,N){
      REP(j,0,N){
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }

  REP(i,0,Q){
    REP(j,0,N){
      if(graph[v[i]-1][j] <= d[i] || v[i]-1 == j) node[j] = c[i];
    }
  }

  REP(i,0,N) cout<<node[i]<<endl;

  return 0;
}
