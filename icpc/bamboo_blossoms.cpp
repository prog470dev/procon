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

const int MAX = 7368791;

int main() {

  while(1){
    int m, n;
    cin>>m>>n;
    if(m==0 && n==0) break;

    bool sieve[MAX+1];
    REP(i,0,MAX+1) sieve[i] = true;

    int p = m;
    REP(i,0,n){
      while(!sieve[p]) p++;
      for(int j = p; j < MAX+1; j += p){
        sieve[j] = false;
      }
    }

    int ans = p;
    while(!sieve[ans]) ans++;
    cout<<ans<<endl;
  }

  return 0;
}
