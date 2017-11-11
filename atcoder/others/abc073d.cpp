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
#include <utility>

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long  LLINF = 1e18;

using namespace std;

int N, M, R;
int r[10];
int load[205][205];
int ans;

void dfs(int state, int visitTown, int cost){
  state |= (1<<visitTown);
  //cout<<"state: "<<state<<", visitTown: "<<visitTown<<", cost: "<<cost<<endl;
  if(state == (1<<R)-1){
    ans = min(ans, cost);
    //cout<<"ans: "<<ans<<endl;
    return;
  }
  REP(i,0,R){
    if((state & (1<<i))) continue;
    int nextState = state | (1<<i);
    int nextTown = i;
    //cout<<"nextTown: "<<nextTown<<endl;
    int nextCost = cost + load[r[visitTown]][r[nextTown]];
    //cout<<cost<<" + "<<load[r[visitTown]][r[nextTown]]<<endl;
    dfs(nextState, nextTown, nextCost);
  }
  return;
}

int main(){
  cin>>N>>M>>R;
  REP(i,0,R) cin>>r[i], r[i]--;

  REP(i,0,N){
    REP(j,0,N){
      load[i][j] = INF;
    }
  }

  REP(i,0,M){
    int a, b, c;
    cin>>a>>b>>c;
    load[a-1][b-1] = c;
    load[b-1][a-1] = c;
  }

  REP(k,0,N){
    REP(i,0,N){
      REP(j,0,N){
        load[i][j] = min(load[i][j], load[i][k] + load[k][j]);
      }
    }
  }

  //test
  // REP(i,0,N){
  //   REP(j,0,N){
  //     cout<<load[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  ans = INF;
  REP(i,0,R){
    dfs(0, i, 0);
  }

  cout<<ans<<endl;

  return 0;
}
