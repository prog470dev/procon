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

int n, m, a, h, p, q;
int amida[105][1005];

int main() {
  while(1){
    cin>>n>>m>>a;
    if(m==0 && m==0 && a==0) break;
    REP(i,0,n)REP(j,0,1005) amida[i][j] = -1;
    REP(i,0,m){
      cin>>h>>p>>q;
      amida[p-1][h] = 1;
      amida[q-1][h] = 0; //:left
    }

    int ans = a-1;
    //REP(i,0,1005){
    for(int i = 1000; 0<=i; i--){
      if(amida[ans][i] == 0){
        ans--;
      }else if(amida[ans][i] == 1){
        ans++;
      }
    }
    cout<<ans+1<<endl;
  }
  return 0;
}
