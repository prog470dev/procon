//どうしたらもうゴールは無理だとわかる？
//-> 同じ街, 同じlimitで、以前より大きいステップ数で訪れる必要なし

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

const int INF = 1000000000;

int N, M, L, K, A, H;
int ans;
bool isfreeze[100];
int visited[100][100];
vector< pair<int, int> > v[100];

void dfs(int town, int limit, int step){
  if(limit < 0 || visited[town][limit] < step) return;
  visited[town][limit] = step;
  if(town == H){
    ans = min(ans, step);
    return;
  }
  //move
  REP(i,0,v[town].size()){
    dfs(v[town][i].first, limit - v[town][i].second, step + v[town][i].second);
  }
  //freeze
  if(isfreeze[town]){
    REP(i,limit,M){
      dfs(town, limit + 1, step+1);
    }
  }
  return;
}

int main() {

  while(1){
    cin>>N>>M>>L>>K>>A>>H;
    if(N==0) break;
    REP(i,0,100) isfreeze[i] = false;
    isfreeze[A] = true;
    isfreeze[H] = true;  //ゴールだからいらないかも？
    REP(i,0,L){
      int t;
      cin>>t;
      isfreeze[t] = true;
    }
    REP(i,0,100) v[i].clear();
    REP(i,0,K){
      int x, y, t;
      cin>>x>>y>>t;
      v[x].push_back(make_pair(y, t));
      v[y].push_back(make_pair(x, t));
    }

    ans = INF;
    REP(i,0,100)REP(j,0,100) visited[i][j] = INF;

    dfs(A, M, 0);

    if(ans == INF) cout<<"Help!"<<endl;
    else cout<<ans<<endl;
  }

  return 0;
}
