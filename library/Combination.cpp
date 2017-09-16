/* コンビネーション(nCr)の簡易版とDP版

概要：異なるn個のものからr個を選ぶ場合の組み合わせの数であり、nCrと表される
	　グローバルで宣言された配列に対し、comb[n][r]で求められる

返り値：①簡易版：long long
		②DP版：void(グローバルでlong longの2次元配列定義)

制限：long longで約n<=50

*/

// 簡易版
long long combination(int n, int r){
	long long ans=1;
	REP(i, 0, r){
		ans*=n-i;
		ans/=i+1;
	}
	return ans;
}

// DP版
long long comb[51][51];
void combinationDP(int n){
	for(int i=0; i < n + 1; i++){
		for(int j=0; j < n + 1; j++){
			if(j==0 || i==j) comb[i][j]=1;
			else comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
		}
	}
}
