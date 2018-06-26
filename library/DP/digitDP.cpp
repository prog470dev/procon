/*
digitDP(桁DP)
概要：
	桁を増やしてDPする。
	入力自体がlong long で受け取れない場合のAからBの範囲の組み合わせ数問題が多い
DP配列の持ち方
	dp[桁][条件][less] := 左からi桁目まで、条件やlessを満たしているかCheck!!
	lessとは:
		1234567
		12までみたとし、3桁目を見てみる。
		122だったら、それ以降の桁は0～9の好きな数を扱える
		124は超えるのでダメ
		123だったらそれ以降の桁も気を使わないといけない。
		故に注目した桁の数字が目指す数字列の同じ桁の数字よりがlessかどうかが大事
	条件とは:
		・数字列にaが複数でたら、ダメとすると
		  dp[桁][aがすでにでたか][less]

		・複数条件があれば配列をたくさん付け加えていい。
		  dp[桁][aがでたか][bがでたか][less]
		  * 特に0~10まで全部についてやりたいときは1<<10で回す

		特にMの倍数の個数を求める系の問題の時は、Mのmodを持つ
		  dp[桁][Mのmod][less]
		(直前の桁までのMのmod)+付け加える数字)のMのmodを持てばOK
*/
#include <iostream>
#include <string>
#define REP(i,n,N) for(ll i=(n); i<(N); i++)
typedef long long ll;
/*0～Nの中でDの倍数となる数*/
ll dp[10010][110][2];
const ll MOD = 1e9+7;
int main() {
    int D; string N; cin >> D >> N;
    int M = N.length();

    dp[0][0][0] = 1;
    REP(i,0,M) REP(j,0,D) REP(less,0,2) {
        int lim = less ? 9 : N[i] - '0'; //すでにlessならその後は9まで見てよし
        REP(x,0,lim+1) {
            int mo = (j + x) % D;
            (dp[i+1][mo][less||x<lim] += dp[i][j][less]) %= MOD;
        }
    }
    ll ans = (dp[M][0][0] + dp[M][0][1] - 1 + MOD) % MOD;
    cout << ans << endl;
}