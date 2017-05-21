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

#define CH(n,A,B) (A<=n&&n<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long;

const int INF = 1e9;
const long long LLINF = 1e15;

using namespace std;

int n,m,c,s,g;
int x,y,dist,comp,p[25],q[25][55],r[25][55];
int d[35][1005][1005], f[1005][1005];

int main() {
  while(1){
    cin>>n>>m>>c>>s>>g;
    if(n==0&&m==0&&c==0&&s==0&&g==0) break;
    s--; g--;
    REP(k,0,c)REP(i,0,n)REP(j,0,n){
      if(i==j) d[k][i][j] = 0;
      else d[k][i][j] = INF;
    }
    REP(i,0,m){
      cin>>x>>y>>dist>>comp;
      x--; y--; comp--;
      d[comp][x][y] = min(dist, d[comp][x][y]);
      d[comp][y][x] = min(dist, d[comp][y][x]);  //多重変あり
    }

    REP(i,0,c) cin>>p[i];
    REP(i,0,c){
      q[i][0] = 0;
      REP(j,1,p[i]){
        cin>>q[i][j];
      }
      q[i][p[i]] = INF;
      REP(j,0,p[i]){
        cin>>r[i][j];
      }
    }

    //各会社についての、任意の駅の最短”距離”
    REP(company,0,c){
      REP(k,0,n)REP(i,0,n)REP(j,0,n) {
        d[company][i][j] = min(d[company][i][j], d[company][i][k]+d[company][k][j]);
      }
    }

    REP(i,0,n)REP(j,0,n){
      if(i==j) f[i][j] = 0;
      else f[i][j] = INF;
    }
    REP(company,0,c){
      //１つの会社のみを使用した場合の、任意の駅間の最低”運賃”
      REP(from,0,n)REP(to,0,n){
        if(d[company][from][to] == INF) continue; //到達不可能なら計算しない
        //二点間の”運賃”を計算
        int fare = 0;
        REP(i,0,p[company]){
          if(q[company][i] > d[company][from][to]) break;
          fare += r[company][i] * min(d[company][from][to]-q[company][i],q[company][i+1]-q[company][i]);
        }
        f[from][to] = min(f[from][to], fare);
      }
    }

    REP(k,0,n){
      REP(i,0,n){
        REP(j,0,n){
          f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
        }
      }
    }
    if(f[s][g] == INF) cout<<-1<<endl;
    else cout<<f[s][g]<<endl;
  }

  return 0;
}
