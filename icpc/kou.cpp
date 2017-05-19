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

set<char> st;
char c[11] = {'y', 'u', 'i','o','p','h','j','k','l','n','m'};

int main() {
  REP(i,0,11){
    st.insert(c[i]);
  }
  string s;
  while(1){
    cin>>s;
    if(s == "#") break;
    int side, ans = 0;
    if(st.find(s[0]) == st.end()) side = 0;
    else side = 1;
    REP(i,1,s.size()){
      if((side == 0 && st.find(s[i]) != st.end()) || (side == 1 && st.find(s[i]) == st.end())) ans++;
      if(st.find(s[i]) == st.end()) side = 0;
      else side = 1;
    }
    cout<<ans<<endl;
  }
  return 0;
}
