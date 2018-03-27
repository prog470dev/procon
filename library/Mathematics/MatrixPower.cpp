#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, n) for(int i=a; i<n; i++)

using namespace std;

/*
行列累乗

引数  ：vector<vector<int>>, vector<vector<int>>

返り値：vector<vector<int>>(正方行列のn乗)

概要  ：正方行列のn乗を求める

計算量：行または列の数をmとするとＯ(log(n) * m^3)

*/
/*==================================================*/

/*==================================================*/
// 行列：A*B
vector<vector<int>> mul(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> C(A.size(), vector<int>(B[0].size()));

	// 初期化
	for (int i = 0; i < C.size(); i++) {
		for (int j = 0; j < C[0].size(); j++) {
			C[i][j] = 0;
		}
	}

	// 行列C = A * Bの計算
	for (int i = 0; i < A.size(); i++) {
		for (int k = 0; k < B.size(); k++) {
			for (int j = 0; j < B[0].size(); j++) {
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
	return C;
}

// 行列：A^n
vector<vector<int>> pow(vector<vector<int>> A, int n) {
	vector<vector<int>> B(A.size(), vector<int>(A[0].size()));

	// 初期化
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[i].size(); j++) {
			if (i == j) B[i][j] = 1;
			else B[i][j] = 0;
		}
	}
	// 行列B = A^nの計算
	while (n > 0) {
		if (n & 1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}

	return B;
}

/*==================================================*/

int main() {
	int n, m;
	vector<vector<int>> a, b;
	cin >> m >> n;

	a.resize(m);
	REP(i, 0, m) {
		REP(j, 0, m) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}

	// m*m行列のn乗
	b = pow(a, n);
	REP(i, 0, b.size()) {
		REP(j, 0, b[i].size()) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
