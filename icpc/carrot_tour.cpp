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
const double DINF = 1e15;

using namespace std;

int n;
double r, angl, x[25], y[25];
double dp[10010][25][25]; /*(得たニンジンの数,今の街,一つ前の町)：個々までの距離の最小値*/
bool reach[25][25][25]; //i->j->kに移動できるか？（角度的に）

int main() {
  cin>>n>>r>>angl;
  angl = angl*(3.1415)/180.0;
  REP(i,0,n) cin>>x[i]>>y[i];
  REP(i,0,n) reach[0][0][i] = true; //スタートからはどこでもイケる。
  REP(i,0,n){
    REP(j,0,n){
      REP(k,0,n){
        /*角度的に到達可能か計算*/
        /*本来移動できない角度でも、小さい方の角度を計算してしまう*/
        if(i==j || j==k) continue;
        double ang, ang1, ang2, x1, y1, x2, y2;
        x1 = x[i] - x[j];
        y1 = y[i] - y[j];
        x2 = x[k] - x[j];
        y2 = y[k] - y[j];
        ang1 = atan2(x1,y1);
        ang2 = atan2(x2,y2);
        ang = fabs(ang1 - ang2);
        if(ang <= angl){
          cout<<"( "<<i<<", "<<j<<", "<<k<<" )"<<endl;
          cout<<">>> ang : "<<ang<<endl;
          reach[i][j][k] = true;
        }
      }
    }
  }
  REP(i,0,10010)REP(j,0,n)REP(k,0,n) dp[i][j][k] = INF;
  REP(i,0,n)REP(j,0,n)dp[0][i][j] = 0;

  REP(carrot,1,10010){
    REP(nowNode,0,n)REP(nextNode,0,n){
      if(nowNode == nextNode) continue;
      REP(prevNode,0,n){  //どこから来たかを選ぶ
        if(prevNode == nowNode) continue;
        if(!reach[prevNode][nowNode][nextNode]) continue;
        double nextDist = sqrt( pow(x[nowNode]-x[nextNode], 2) + pow(y[nowNode]-y[nextNode], 2));
        //cout<<"nextDist : "<<nextDist<<endl;
        dp[carrot][nowNode][nextNode] = min(dp[carrot][nowNode][nextNode], dp[carrot-1][prevNode][nowNode]+nextDist);
      }
    }
  }
  int ans = 0;
  REP(i,0,10010){
    REP(j,0,n){
      REP(k,0,n){
        if(dp[i][j][k] <= r) ans = i;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
