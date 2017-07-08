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

int X, Y, N;

int main(){
  cin>>X>>Y>>N;
  vector<int> A(N);
  REP(i,0,N) cin>>A[i];
  REP(i,0,N-1){
    if(Y*A[i] > X*A[i+1]){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
