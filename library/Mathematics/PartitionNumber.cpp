#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, n) for(int i=a; i<n; i++)
const int MOD = 1e9 + 7;

using namespace std;

/*
分割数

概要：0以上の整数nを、順序を区別せずに自然数の和に分ける場合の数のMOD
Q(i,j) := 整数iを順序を区別せずに「j個の自然数」の和に分ける場合の数
R(i,j) := 整数iを順序を区別せずに「j個以下の自然数」の和に分ける場合の数

引数：

返り値：

計算量：Ｏ(n^2)

*/

/*==================================================*/
// 分割数のMODを求める
template<typename T> struct PartitionNumber {
	int n;
	vector<T> _P; vector<vector<T>> _PP, _Q, _R;
	PartitionNumber(int _n) {
		n = _n;
		_P.resize(n + 1);
		_PP.resize(n + 1, vector<T>(n + 1));
		_Q.resize(n + 1, vector<T>(n + 1));
		_R.resize(n + 1, vector<T>(n + 1));

		_Q[0][0] = 1;
		REP(i, 1, n + 1) REP(j, 1, n + 1) {
			_Q[i][j] += _Q[i - 1][j - 1] % MOD;
			if (j <= i) _Q[i][j] += _Q[i - j][j] % MOD;
		}
		REP(i, 0, n + 1) {
			_R[i][0] = _Q[i][0];
			REP(j, 1, n + 1) _R[i][j] = _R[i][j - 1] + _Q[i][j] % MOD;
		}
	}

	int R(int i, int j) {
		return _R[i][j] % MOD;
	}
	int Q(int i, int j) {
		return _Q[i][j] % MOD;
	}
};

/*==================================================*/

PartitionNumber<int> pn(1010);  // 1から1010までの分割数

int main() {
	cout << "Q(i, j)"  << endl;
	cout << pn.Q(7, 3) << endl; // 整数7を3個の自然数に分割したときの組み合わせ数のmod
	cout << pn.Q(7, 2) << endl;
	cout << pn.Q(7, 1) << endl;

	cout << "R(i, j)"  << endl;
	cout << pn.R(7, 3) << endl; // 整数7を3個以下の自然数に分割したときの組み合わせ数のmod
	cout << pn.R(7, 2) << endl;
	cout << pn.R(7, 1) << endl;
	return 0;
}