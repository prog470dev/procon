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

  int N, K, A[100005];
  cin>>N>>K;
  REP(i,0,N) cin>>A[i];

  sort(A, A+N);

  long long ans = 0;
  REP(i,0,K){
    ans += (A[i] + i);
  }

  cout<<ans<<endl;

  return 0;
}
