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

map<int,int> m;
string S;
int ans = 1;

int main(){
  cin>>S;
  REP(i,0,S.size()) m[S[i]]++;
  REP(i,1,S.size()+1) ans *= i;
  for(auto mm : m){
    int tmp = 1;
    REP(i,1,mm.S+1){
      tmp *= i;
    }
    ans /= tmp;
  }
  cout<<ans-1<<endl;
  return 0;
}
