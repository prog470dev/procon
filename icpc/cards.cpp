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

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long;

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

int M, N, B[510], R[510];

//２つの数の最大公約数があれば、ペアにできる

int main() {
  while(1){
    cin>>M>>N;
    if(M==0&&N==0) break;
    REP(i,0,M) cin>>B[i];
    REP(i,0,N) cin>>R[i];

  }
  return 0;
}
