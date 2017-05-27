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
#define F first
#define S second
#define ll long long;

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

int main() {
  int N, A, B;
  cin>>N>>A>>B;
  if(A > B || (N < 2 && A!=B)){
    cout<<0<<endl;
    return 0;
  }
  cout<<((N-1)*B+A) - ((N-1)*A+B) +1<<endl;
  return 0;
}
