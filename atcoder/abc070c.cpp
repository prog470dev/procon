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

/*===========================================*/

ll gcd( ll a, ll b){
  if(b == 0){
    return a;
  }
  return gcd(b, a % b);
}

ll lcm( ll a, ll b )
{
	return a / gcd(a, b) * b;
}

/*===========================================*/

int N;
ll T[105];

int main(){
  cin>>N;
  REP(i,0,N){
    cin>>T[i];
  }

  ll ans = T[0];
  REP(i,1,N){
    ans = lcm(ans, T[i]);
  }

  cout<<ans<<endl;

  return 0;
}
