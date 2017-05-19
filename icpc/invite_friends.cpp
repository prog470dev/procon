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

  int N, a, b, imos[1000005]={1};
  cin>>N;
  REP(i,0,N){
    cin>>a>>b;
    imos[a]++;
    imos[b+1]--;
  }
  REP(i,1,1000005) imos[i] += imos[i-1];

  int ans = 0;
  REP(i,0,1000005){
    if(imos[i] >= i) ans = max(ans, i);
  }

  cout<<ans-1<<endl;
  
  return 0;
}
