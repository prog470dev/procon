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

int Q;
string s;

int main() {
  cin>>Q;
  REP(i,0,Q){
    cin>>s;
    int ans = 0;
    set<string> se;
    while(1){
      if(se.find(s)!=se.end()){
        cout<<-1<<endl;
        break;
      }
      se.insert(s);
      if(s.size()==1){
        cout<<ans<<endl;
        break;
      }
      ans++;
      int m = 0;
      REP(pos,1,s.size()){
        string left = s.substr(0,pos);
        string right = s.substr(pos,s.size()-pos);
        m = max(m, stoi(left)*stoi(right));
      }
      s = to_string(m);
    }
  }

  return 0;
}
