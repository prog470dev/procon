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

int INF = 1000000000;

int main() {

  int N, M, a[55], b[55], c[55], d[55];

  cin>>N>>M;
  REP(i,0,N) cin>>a[i]>>b[i];
  REP(i,0,M) cin>>c[i]>>d[i];

  REP(i,0,N){
    int ans = INF, no = -1;
    REP(j,0,M){
      if(ans > abs(a[i]-c[j]) + abs(b[i]-d[j])){
        ans = abs(a[i]-c[j]) + abs(b[i]-d[j]);
        no = j;
      }
    }
    cout<<no+1<<endl;
  }

  return 0;
}
