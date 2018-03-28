#include <algorithm>
#include <iostream>

using namespace std;

/*
概要  ：①最大公約数(gcd)
②最小公倍数(lcm)

引数  ：①long long a, long long b
②long long a, long long b

返り値：①long long
②long long

概要  ：与えられた整数(long long型)a, bの
①最大公約数(gcd)
②最小公倍数(lcm) を求める

計算量：Ｏ(logn)

*/

/*==================================================*/

/*==================================================*/
// ※大小関係は考えなくてよい

// 最大公約数
long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

// 最小公倍数
long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}

/*==================================================*/

int main() {
	long long a, b;
	cin >> a >> b;

	// 最大公約数
	cout << "gcd(" << a << "," << b << ")=" << gcd(a, b) << endl;

	// 最小公倍数
	cout << "lcm(" << a << "," << b << ")=" << lcm(a, b) << endl;

	return 0;
}