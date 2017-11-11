/*
・因数分解：縦と横は独立に計算できる。
*/

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

int n, m;
long long x[100005], y[100005], MOD = 1000000007;

int main() {

  cin>>n>>m;
  REP(i,0,n) cin>>x[i];
  REP(i,0,m) cin>>y[i];

  long long sumx=0, sumy=0;

  REP(i,0,n) sumx = ( sumx - (n-i-1)*x[i] + (i)*x[i] ) % MOD;
  REP(i,0,m) sumy = ( sumy - (m-i-1)*y[i] + (i)*y[i] ) % MOD;

  cout<<sumx*sumy%MOD<<endl;

  return 0;
}
