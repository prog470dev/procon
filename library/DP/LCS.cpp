/*

LCS(最長共通部分列)

引数: string a , string b
返り値: LCSの長さ(int 型)

概要:
	dp表を以下の規則で埋める
	・左上の文字が一致している   左上のLCS + 1
	・左上の文字が一致していない max(上のLCS、左のLCS)
	ex) a= "abcd" , b = "acd"
		  - a b c d
		- 0 0 0 0 0
		a 0 1 1 1 1
		c 0 1 1 2 2
		d 0 1 1 2 3 <-これを返す。
*/

int dp[1010][1010];

int LCS(string a,string b){
	// init
	REP(i,0,a.size()+1) dp[i][0] = 0;
	REP(j,1,b.size()+1) dp[0][j] = 0;

	// DP
	REP(i, 0, a.size()){
		REP(j, 0, b.size()){
			if(a[i] == b[j])
				dp[i+1][j+1] = dp[i][j] + 1;
			else
				dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
		}
	}
	return dp[a.size()][b.size()];
}