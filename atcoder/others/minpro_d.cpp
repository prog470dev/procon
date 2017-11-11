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
  long long ans = 0;

  int Q, K;
  cin>>Q>>K;
  int q, d, a;
  REP(i,0,Q){
    cin>>q;
    if(q ==1){
      cin>>d>>a;
      ans += max(K*d, a);

    }else{
      cin>>d;
      cout<<ans<<endl;
    }
  }

  return 0;
}
