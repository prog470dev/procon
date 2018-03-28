#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, n) for(int i=a; i<n; i++)

using namespace std;

/*
素因数分解

引数  ：int n

返り値：vector<pair<int, int>> (first：素因数, second：素因数の数)

概要  ：与えられた整数の素因数とその数をvectorで持ち、返り値とする

計算量：Ｏ(sqrt(n))

*/

/*==================================================*/

/*==================================================*/
vector<pair<int, int>> prime_factor(int n) {
	vector<pair<int, int>> vp;

	// iがsqrt(n)となるまで繰り返す
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {  // iが素因数
			vp.emplace_back(i, 0);

			// 素因数の数を求める
			do {
				vp[vp.size() - 1].second++;
				n /= i;
			} while (n%i == 0);
		}
	}

	if (n != 1) vp.emplace_back(n, 1);
	return vp;
}

/*==================================================*/

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> pf = prime_factor(n);
	REP(i, 0, pf.size()) cout << pf[i].first << ":" << pf[i].second << endl;

	return 0;
}