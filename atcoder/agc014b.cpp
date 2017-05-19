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

int N, M, a[100010], b[100010];

int main() {
  cin>>N>>M;
  REP(i,0,M){
    cin>>a[i]>>b[i];
    a[i]--; b[i]--;
  }

  int d[100010];
  REP(i,0,N) d[i] = 0;
  REP(i,0,M){
    if(a[i]!=0) d[a[i]]++;
    if(b[i]!=0) d[b[i]]++;
  }

  REP(i,1,N){
    if(d[i]%2 == 1){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;

  return 0;
}
