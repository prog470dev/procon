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

  int N, M, T, a[105];
  cin>>N>>M>>T;
  REP(i,0,N) cin>>a[i];

  int ans = a[0] - M;
  REP(i,1,N){
    ans += max(0, (a[i]-M*2) - a[i-1]);
  }
  ans += max(0, T - (a[N-1] + M));
  
  cout<<ans<<endl;

  return 0;
}
