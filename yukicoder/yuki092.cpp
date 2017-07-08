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
const long long  LLINF = 1e15;

using namespace std;

int N, M, K;
int d[1010];
vector< pair<int, int> > edge[1010];

bool clear[110][1010]; //clear[i][j] := ノードiで、d[j]までクリアできるか？

void dfs(int curNode, int step){  //現在のノード、次に達成するべきDのインデックス
  if(step == K) return;
  REP(i,0,edge[curNode].size()){
    if(edge[curNode][i].S == d[step] && !clear[edge[curNode][i].F][step]){
      clear[edge[curNode][i].F][step] = true;
      dfs(edge[curNode][i].F,step+1);
    }
  }
  return;
}

int main(){
  cin>>N>>M>>K;
  REP(i,0,M){
    int a, b, c;
    cin>>a>>b>>c;
    edge[a-1].push_back(make_pair(b-1,c));
    edge[b-1].push_back(make_pair(a-1,c));
  }
  REP(i,0,K) cin>>d[i];
  REP(i,0,N)REP(j,0,K) clear[i][j] = false;
  REP(i,0,N){
    dfs(i,0);
  }
  vector<int> ans;
  REP(i,0,N){
    if(clear[i][K-1]) ans.push_back(i+1);
  }
  cout<<ans.size()<<endl;
  REP(i,0,ans.size()) cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}
