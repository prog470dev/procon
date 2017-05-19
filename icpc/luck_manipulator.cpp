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

  int N, A, B, C, X, Y[105];
  while(1){
    cin>>N>>A>>B>>C>>X;
    if(N==0) break;
    REP(i,0,N) cin>>Y[i];

    int cnt = 0, i = 0;
    for(i=0;i<10001;i++){
      if(Y[cnt] == X) cnt++;
      if(cnt == N) break;
      X = (A*X + B)%C;
    }

    if(cnt == N) cout<<i<<endl;
    else cout<<-1<<endl;
  }

  return 0;
}
