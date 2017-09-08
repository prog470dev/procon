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
#include <deque>
#include <algorithm>

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long  LLINF = 1e18;

using namespace std;

int main(){

  string S;
  cin>>S;

  set<int> st;
  REP(i,0,S.size()){
    st.insert(S[i] - 'a');
  }

  REP(i,0,26){
    if(st.find(i) == st.end()){
      cout<<(char)('a' + i)<<endl;
      return 0;
    }
  }

  cout<<"None"<<endl;

  return 0;
}
