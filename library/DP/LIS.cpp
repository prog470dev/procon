/*

LIS(最長増加部分列)

引数: int n //調べる数列の長さ
返り値: LISの長さ(int)

概要:
	O(nlogn)
	今から調べる数列をa[]とする
	・dp配列をinfで初期化
	・dpの先頭から見て、a[i] <= dp[i]なら書き換える
	  (これを二分探索で高速化している)

	増加部分列はdp[i] < dp[i+1]である

	ex) 6
		1 3 2 3 3 4

		inf inf inf inf inf inf inf //初期化
		  1 inf inf inf inf inf inf //inf → 1 に書き換え
		  1   3 inf inf inf inf inf //inf → 3
		  1   2 inf inf inf inf inf //  3 → 2
		  1   2   3 inf inf inf inf //inf → 3
		  1   2   3 inf inf inf inf //  3 → 3
		  1   2   3   4 inf inf inf //inf → 4

応用:
	・入れ子構造(マトリョーシカみたいなの)に使える
	・二次元ならpairでもって、sort
	  secondのとこだけでLISを求めれば、二次元LIS
*/

const int inf=1e9;

int a[100010]; //調べる数列
int LIS(int n){
	int dp[100010];
	REP(i,0,n) dp[i]=inf;
	REP(i,0,n){
		*lower_bound(dp,dp+n,a[i])=a[i];
	}
	return lower_bound(dp,dp+n,inf)-dp;
}
