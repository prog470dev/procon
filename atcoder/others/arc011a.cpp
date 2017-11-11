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

  int m, n, N;
  cin>>m>>n>>N;

  int ans = N;
  int t = 0;
  while(1){
    ans += ((N+t)/m)*n;

    /*t,Nどちらの計算でもお互いの数を使うので、一旦計算結果を取っておく。*/
    int tt = (N+t)%m;
    int tN = ((N+t)/m)*n;

    t = tt;
    N = tN;

    if(N + t < m) break;
  }

  cout<<ans<<endl;

  return 0;
}
