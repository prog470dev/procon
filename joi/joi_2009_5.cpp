/*
2017_06_14_AC
<point>
・「次の行動に影響を与える”要素”は何か？」を考える.（実験でイメージする.）
　→　DPに落とし込む事が可能。
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
#include <deque>
#include <algorithm>

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long  LLINF = 1e18;

using namespace std;

const ll MOD = 100000;

int W,H;
/*座標（y,x), どのようにたどり着いたか(0:上直,1:右直,2:上曲,3:右曲)*/
ll dp[110][110][4];

int main(){
  cin>>W>>H;
  REP(i,0,H) dp[i][0][0] = 1;
  REP(i,0,W) dp[0][i][1] = 1;
  REP(i,1,H)REP(j,1,W){
    dp[i][j][0] = (dp[i-1][j][0]+dp[i-1][j][2])%MOD;
    dp[i][j][1] = (dp[i][j-1][1]+dp[i][j-1][3])%MOD;
    dp[i][j][2] = dp[i-1][j][1];
    dp[i][j][3] = dp[i][j-1][0];
  }
/*
  RREP(i,0,H){
    REP(j,0,W){
      cout<<"[";
      REP(k,0,4){
        cout<<dp[i][j][k]<<",";
      }
      cout<<"]";
    }
    cout<<endl;
  }
*/
  ll ans = 0;
  REP(k,0,4){
    ans = (ans+dp[H-1][W-1][k])%MOD;
  }
  cout<<ans<<endl;
  return 0;
}
