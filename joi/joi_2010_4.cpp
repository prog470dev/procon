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

int N;
ll D[110],dp[110][25];

int main(){
  cin>>N;
  REP(i,0,N) cin>>D[i];
  REP(i,0,21){
    if(i == D[0]) dp[i][0] = 1;
  }
  REP(i,1,N-1){
    REP(j,0,21){
      if(0<=j-D[i]) dp[j][i] += dp[j-D[i]][i-1];
      if(j+D[i]<=20) dp[j][i] += dp[j+D[i]][i-1];
    }
  }
  cout<<dp[D[N-1]][N-2]<<endl;
/*
  REP(j,0,21){
    REP(i,0,N-1){
      cout<<dp[j][i]<<" ";
    }
    cout<<endl;
  }
  */
  return 0;
}
