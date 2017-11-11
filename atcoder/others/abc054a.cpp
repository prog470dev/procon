#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int main() {

  int A,B;
  cin>>A>>B;

  if(A == 1) A=14;
  if(B == 1) B=14;

  if(A > B) cout<<"Alice"<<endl;
  else if(A < B) cout<<"Bob"<<endl;
  else cout<<"Draw"<<endl;

  return 0;
}
