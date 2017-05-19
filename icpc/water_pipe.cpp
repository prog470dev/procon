/*
2017_05_06_AC
<point>
・ｓとg1,g2の間に、必ずハブ的なノードができるので、そこを経由した場合の最小値を出す。
・この場合、経路が被ることはないのでオーバーラップは考慮しなくて良い。
　（road[s][k]+road[k][g[0]]+road[k][g[1]]の各項は経路がかぶらない。）
<caution>
・road[k][g[0]]+road[k][g[1]]が、(k:anyの中で)最小だからといって、
　road[s][k]まで考慮したときも最小だとは限らない。
　（road[k][g[0]]+road[k][g[1]]が大きくても、road[s][k]が小さければ、合計は最小になる）
・INF=1e9としてしまうと、WFの更新式の中でのINF同士の足し算で、オーバーフロウしてしまう。
　→ ２分の一にする。（1e9 -> 1e8）
*/

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

const int INF = 1e8;

int n ,m, s, g[2];
int road[105][105];

int main() {
  while(1){
    cin>>n>>m>>s>>g[0]>>g[1];
    if(n==0) break;
    s--; g[0]--; g[1]--;
    REP(i,0,n)REP(j,0,n){
      if(i==j) road[i][j] = 0;
      else road[i][j] = INF;
    }
    REP(i,0,m){
      int b1,b2,c;
      cin>>b1>>b2>>c;
      b1--; b2--;
      road[b1][b2] = c;
    }
    REP(k,0,n){
      REP(from,0,n){
        REP(to,0,n){
          road[from][to] = min(road[from][to], road[from][k]+road[k][to]);
        }
      }
    }
    int ans = INF;
    REP(k,0,n){
      ans = min(ans, road[s][k] + road[k][g[0]] + road[k][g[1]]);
    }
    cout<<ans<<endl;
  }
  return 0;
}
