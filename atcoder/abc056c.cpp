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

  int X;
  cin>>X;

  int cnt = 0, ans = 0;
  REP(i,1,1000000000){
    cnt += i;
    ans++;
    if(X <= cnt) break;
  }

  cout<<ans<<endl;

  return 0;
}
