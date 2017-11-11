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
#include <utility>

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

  set<int> st;
  int N, A;

  cin>>N;
  REP(i,0,N){
    cin>>A;
    if(st.find(A) == st.end()) st.insert(A);
    else st.erase(A);
  }

  cout<<st.size()<<endl;

  return 0;
}
