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

int main() {

  string A, B, C;
  cin>>A>>B>>C;
  if(A[A.size()-1] == B[0] && B[B.size()-1] == C[0]) cout <<"YES"<<endl;
  else cout <<"NO"<<endl;

  return 0;
}