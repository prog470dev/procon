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

int N;
string s[105];

int main() {
  while(1){
    cin>>N;
    if(N==0) break;
    REP(i,0,N) cin>>s[i];
    int ls = 0, rs = 0, prev = 0, ans = 0;
    REP(i,0,N){
      if(s[i] == "lu") ls = 1;
      if(s[i] == "ld") ls = 0;
      if(s[i] == "ru") rs = 1;
      if(s[i] == "rd") rs = 0;

      if(ls==0&&rs==0){
        if(prev != 0) ans++;
        prev = 0;
      }else if(ls==1&&rs==1){
        if(prev != 1) ans++;
        prev = 1;
      }/*else{
        prev = 2;
      }*/
    }
    cout<<ans<<endl;
  }
  return 0;
}
