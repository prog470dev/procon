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

int main() {

  long long N, a[300005];

  cin>>N;
  REP(i,0,3*N) cin>>a[i];

  sort(a,a+3*N,greater<long long >());

  long long ans = 0;
  REP(i,0,2*N) {
    if(i%2 == 1) ans += a[i];
  }

  cout<<ans<<endl;

  return 0;
}
