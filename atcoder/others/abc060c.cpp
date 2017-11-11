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

int main() {

  long long  N, T;
  long long  t[200005];
  cin>>N>>T;
  REP(i,0,N) cin>>t[i];

  long long r = t[0]+T;
  long long sum = T*N;
  REP(i,1,N){
    if(t[i] < r){
      sum -= (r - t[i]);
    }
    r = t[i] + T;
  }

  cout<<sum<<endl;

  return 0;
}
