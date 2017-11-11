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
  string O, E;
  cin>>O>>E;
  REP(i,0,O.size() + E.size()){
    if(i%2 == 0) cout<<O[i/2];
    else cout<<E[i/2];
  }

  cout<<endl;
  
  return 0;
}
