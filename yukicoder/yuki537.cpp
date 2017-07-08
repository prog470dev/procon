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
  ll N, M;
  cin>>N>>M;
  ll f0 = 0, f1 = 1, f2;
  REP(i,2,N){
    f2 = (f0 + f1)%M;
    f0 = f1;
    f1 = f2;
  }
  cout<<f2 % M<<endl;
  return 0;
}
