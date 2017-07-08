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

int N, kscore, a, ans = 1;

int main(){
  cin>>N;
  REP(i,0,N){
    cin>>a;
    if(i == 0) kscore = a;
    else{
      if(a > kscore) ans++;
    }
    cout<<ans<<endl;
  }

  return 0;
}