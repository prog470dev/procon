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

long long INF = 10000000000;

long long f(long long n){
  int ret = 0;
  while(n != 0) ret++, n /= 10;
  return ret;
}

int main() {

  long long N;
  cin>>N;

  vector<long long> v;
  for(long long  i = 1; i*i <= N; i++){
    if(N % i == 0) v.push_back(i);
  }

  long long ans = INF;
  REP(i,0,v.size()){
    ans = min( ans, f( max(v[i], N/v[i])) );
  }

  cout<<ans<<endl;

  return 0;
}
