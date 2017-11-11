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
long long N, S[105];

int main() {
  cin>>N;
  long long sumd = 0, sum = 0;
  REP(i,0,N){
    cin>>S[i];
  }

  sort(S,S+N);
  RREP(i,0,N){
    long long  tsumd = sumd + S[i];
    long long  tsum = sum + S[i];
    if(tsumd % 10 == 0) sumd = max(sumd, tsumd);
    if(tsum % 10 == 0) sumd = max(sumd, tsum);
    if(tsumd % 10 != 0) sum = max(sum, tsumd);
    if(tsum % 10 != 0) sum = max(sum, tsum);
  }
  cout<<sum<<endl;

  return 0;
}
