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

int n;
string s;

int main() {
  cin>>n;
  REP(i,0,n){
    cin>>s;
    set<string> st;
    REP(k,1,s.size()){
      string train[4];
      train[0] = s.substr(0,k);
      train[1] = s.substr(k,s.size()-k);
      train[2]="", train[3]="";
      REP(j,0,train[0].size()) train[2] += train[0][train[0].size()-1-j];
      REP(j,0,train[1].size()) train[3] += train[1][train[1].size()-1-j];
      REP(ii,0,4){
        REP(jj,0,4){
            if(ii%2 != jj%2) st.insert(train[ii]+train[jj]);
        }
      }
    }
    cout<<st.size()<<endl;
  }
  return 0;
}
