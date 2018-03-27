#include "stdafx.h"
#include <algorithm>
#include <iostream>

using namespace std;

/* コンビネーション(nCr)の簡易版とDP版

概要  ：異なるn個のものからr個を選ぶ場合の組み合わせの数であり、nCrと表される
        グローバルで宣言された配列に対し、comb[n][r]で求められる

引数  ：①簡易版：int n, int r
        ②DP版  ：int n

返り値：①簡易版：long long
        ②DP版  ：void(グローバルでlong longの2次元配列定義)

制限　：long longで約n<=50

計算量：①Ｏ(n)
      　②DP配列作成にＯ(n^2), 参照にＯ(1)

 */

/*==================================================*/
long long comb[51][51];

/*==================================================*/
// 簡易版
long long combination(int n, int r) {
	long long ans = 1;
	for (int i = 0; i < r; i++) {
		ans *= n - i;
		ans /= i + 1;
	}
	return ans;
}

// DP版
void combinationDP(int n) {
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (j == 0 || i == j) comb[i][j] = 1;
			else comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
}

/*==================================================*/

int main() {
	int n, r;
	cin >> n >> r;

	// 簡易版
	cout << n << "C" << r << " = " << combination(n, r) << endl;

	// DP版
	combinationDP(n);
	cout << n << "C" << r << " = " << comb[n][r] << endl;

	return 0;
}