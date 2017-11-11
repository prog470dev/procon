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
#define F first
#define S second

const int INF = 1e9;
const long long LLINF = 1e18;

using namespace std;

int N;
long long a[300005];
long long sum1[100005], sum2[100005];

int main() {
  cin>>N;
  REP(i,0,3*N) cin>>a[i];

  long long ans = -LLINF;

  priority_queue<long long> PQ1,PQ2;

  REP(i,0,N) PQ1.push(-a[i]), sum1[0]+=a[i];
  RREP(i,2*N,3*N) PQ2.push(a[i]), sum2[N]+=a[i];

  REP(i,N,2*N){
    sum1[i-N+1] = sum1[i-N];
    sum1[i-N+1] += a[i];
    PQ1.push(-a[i]);
    sum1[i-N+1] += PQ1.top();
    PQ1.pop();
  }
  RREP(i,N,2*N){
    sum2[i-N] = sum2[i-N+1];
    sum2[i-N] += a[i];
    PQ2.push(a[i]);
    sum2[i-N] -= PQ2.top();
    PQ2.pop();
  }

  REP(i,0,N+1){
    ans = max(ans,sum1[i]-sum2[i]);
  }

  cout<<ans<<endl;

  return 0;
}
