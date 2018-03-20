/*
bitDP

概要：状態をbitで管理してDPを行う

制限：状態数nとして、n<=16

適用例：
int dp[1 << n];
int main() {
	REP(mask, 0, 1<<n) {                   // 全状態(2^n)に対して処理
		REP(i, 0, n) {
			if (mask & (1 << i)) continue; // bitが立っていたらcontinue

      // bitの立っていない状態に対して処理
			//
			//
			dp[mask | (1 << i)] = max(dp[mask | (1 << i), ...); // bitを立てて更新
		}
	}

	cout << dp[(1 << n) - 1] << endl;      // 全てのbitが立っている
	return 0;
}
*/
