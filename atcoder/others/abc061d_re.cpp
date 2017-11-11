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

using namespace std;

const long long INF = 1LL<<50;

int N,M;
long long a[2010], b[2010], c[2010];

int main() {
  cin>>N>>M;

  REP(i,0,M){
    cin>>a[i]>>b[i]>>c[i];
    c[i] = (-1)*c[i];
  }

  //BF
  long long d[1010];
  REP(i,0,N) d[i] = INF;
  d[0] = 0;

  REP(i,0,N-1){
    REP(j,0,M){
      if(d[a[j]-1]==INF) continue; /*0から到達不可能な起点は除外*/
      long long t;
      if(d[a[j]-1]+c[j] <= (-1)*INF) t = (-1)*INF;
      else t = d[a[j]-1]+c[j];
      d[b[j]-1] = min(d[b[j]-1], t);
    }
  }
  long long ans = d[N-1];

  REP(i,0,2*N){
    REP(j,0,M){
      if(d[a[j]-1]==INF) continue;
      long long t;
      if(d[a[j]-1]+c[j] <= (-1)*INF) t = (-1)*INF;
      else t = d[a[j]-1]+c[j];
      d[b[j]-1] = min(d[b[j]-1], t);
    }
  }

  /*d[N-1]が更新される => 0->N-1 の経路のどっかで正の閉路が存在する
  (２回めの更新はN回回すだけでいいのか？)*/
  if(ans != d[N-1]) cout<<"inf"<<endl;
  else cout<<(-1)*ans<<endl;

  return 0;
}
