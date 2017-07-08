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
const long long  LLINF = 1e15;

using namespace std;

int main(){
  ll N;
  cin>>N;
  set<string> st;
  for(ll i = 1; i*i <= N; i++){
    if(N%i != 0) continue;
    ll num = N/i;
    if(st.find(to_string(num)+to_string(i)) == st.end()) st.insert(to_string(num)+to_string(i));
    if(st.find(to_string(i)+to_string(num)) == st.end()) st.insert(to_string(i)+to_string(num));
  }
  cout<<st.size()<<endl;
  return 0;
}
