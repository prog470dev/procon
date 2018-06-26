/*
 * 戻すDP
 *
 * dpは使うものを選んで行くが
 * 選んだものを戻したいときに使う
 *
 * 例えば dp[i][j]:=iまででj個使う
 * の時のDP更新式が
 * dp[i+1][j] = dp[i+1][j-1] - dp[i][j-1-A[i]] + dp[i][j]
 * となったとする(重複組合せDP)。これを書き換えると
 * dp[i][j] = dp[i+1][j] - dp[i+1][j-1]  + dp[i][j-1-A[i]]
 *　となる。
 *
 * ここでdp2[i][j]:=i以外でj個使うということを考える
 * iをN番目の物とみなすことで
 * dp2[i][j] = dp[N][j] - dp[N][j-1]  + dp2[i][j-1-A[i]]
 * ってなるらしい
 *
 * とりあえず
 * 配るDPを普通にやる→左辺をdp[i][j]だけの式に書き換える→i+1の部分をNに書き換える
 *　
 *　全体ではM個選ぶが, 物iをx個だけしか選んじゃダメというときは, 物i以外をM-X個選ぶ方法なので
 * dp2[i][M-x]という使い方をする
 * */

// ABC017D https://arc028.contest.atcoder.jp/tasks/arc028_4

#include <iostream>
#define REP(i,n,N) for(ll i=(n); i<(N); i++)
typedef long long ll;
using namespace std;
const ll mod=1e9+7;

ll dp1[2010][2010];
ll dp2[2010][2010];
int N,M,Q;
int x,y;
int A[2010];
int main() {
    cin>>N>>M>>Q;
    REP(i,0,N) cin>>A[i];
    REP(i,0,N+1) dp1[i][0]=1;
    REP(i,0,N) REP(j,0,M) {
        dp1[i+1][j+1]=dp1[i+1][j]+dp1[i][j+1];
        if(j-A[i]>=0) dp1[i+1][j+1]+=mod-dp1[i][j-A[i]];
        dp1[i+1][j+1]%=mod;
    }
    REP(i,0,N) REP(j,0,M+1) {
        dp2[i][j]=dp1[N][j];
        if(j) dp2[i][j]+=mod-dp1[N][j-1];
        if(j-1-A[i]>=0) dp2[i][j]+=dp2[i][j-1-A[i]];
        dp2[i][j]%=mod;
    }

    REP(k,0,Q) {
        cin>>x>>y;
        p(dp2[x-1][M-y]);
    }
    return 0;
}


