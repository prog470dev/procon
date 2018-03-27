#include <algorithm>
#include <iostream>

using namespace std;

/*
概要  ：高速な累乗(mod対応版)

引数  ：aのb乗のmod(long long型)

返り値：累乗のmod(long long型)

計算量：Ｏ(log a)

※modしない場合は mod に inf をいれること

※0のb乗は1になってます。

*/

/*==================================================*/
const long long mod = 1e9 + 7;

/*==================================================*/
long long fast_power(long long a, long long b) {
	long long ret = 1;
	// aが負の場合
	if (a < 0) {
		a = -a;
		if (b % 2 == 1) ret = -1;
	}
	// 累乗計算
	while (b>0) {
		if (b & 1) {
			ret *= a;
		}
		a *= a;
		a %= mod;
		ret %= mod;
		b >>= 1;
	}
	return ret;
}

/*==================================================*/

int main() {
	long long a, b;
	cin >> a >> b;

	// a^b
	cout << a << "^" << b << " = " << fast_power(a, b) << endl;

	return 0;
}