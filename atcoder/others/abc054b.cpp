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

  int N,M;
  string A[55], B[55];
  cin>>N>>M;
  REP(i,0,N) cin>>A[i];
  REP(i,0,M) cin>>B[i];

  bool flag = false;

  REP(i,0,N){
    REP(j,0,N){
      if(N-i < M || N-j < M) continue;
      int cnt = 0;
      REP(k,0,M){
        REP(l,0,M){
          if(A[i+k][j+l] == B[k][l]) cnt++;
        }
      }
      if(cnt == M*M) flag = true;
    }
  }

  if(flag) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}
