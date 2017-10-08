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


/*==================================================*/

/*==================================================*/

int K, T, a[105];

int main(){

  cin>>K>>T;
  REP(i,0,T) cin>>a[i];

  if(T == 1){
    cout<<a[0]-1<<endl;
    return 0;
  }

  sort(a,a+T);
  int sum = 0;
  REP(i,0,T-1){
    sum += a[i];
  }
  int ans = max(0, (a[T-1]-1) - sum);

  cout<<ans<<endl;

  return 0;
}
