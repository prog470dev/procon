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

  string s;
  int y = 0, a =0, h = 0, o = 0;
  cin>>s;
  for(int i=0; i<s.size(); i++){
    if(s[i] == 'y') y++;
    if(s[i] == 'a') a++;
    if(s[i] == 'h') h++;
    if(s[i] == 'o') o++;
  }

  if(y == 1 && a == 1 && h == 1 && o == 2) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

  return 0;
}
