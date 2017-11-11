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

int t[105];

int main(){

  int A,B,C,D;
  int ans = 0;
  cin>>A>>B>>C>>D;

  REP(i,A,B){
    t[i]++;
  }
  REP(i,C,D){
    t[i]++;
    if(t[i] == 2) ans++;
  }

  cout<<ans<<endl;

  return 0;
}
