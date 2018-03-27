#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/*
概要  ：与えられた文字列がnの倍数か求める
①3の倍数 	各桁の 和 が 3の倍数か
②9の倍数	各桁の 和 が 9の倍数か
③11の倍数	奇数桁 - 偶数桁 が 0 か

引数  ：string(0～9の数字のみ)

返り値：bool(満たすならtrue, 満たさないならfalse)

計算量：Ｏ(n)

*/

/*==================================================*/

/*==================================================*/
bool is3bai(string s) {
	long long ret = 0;
	for (int i = 0; i < s.size(); i++) {
		ret += (s[i] - '0');
		ret %= 3;
	}
	return ret % 3 == 0;
}

bool is9bai(string s) {
	long long ret = 0;
	for (int i = 0; i < s.size(); i++) {
		ret += (s[i] - '0');
		ret %= 9;
	}
	return ret % 9 == 0;
}

bool is11bai(string s) {
	long long ret = 0;
	int minus = 1;
	for (int i = 0; i < s.size(); i++) {
		ret += (-minus)*(s[i] - '0');
		minus = -minus;
	}
	return ret == 0;
}

/*==================================================*/

int main() {
	string s, t, u;
	cin >> s >> t >> u;

	cout << s << ":" << is3bai(s) << endl;
	cout << s << ":" << is9bai(s) << endl;
	cout << s << ":" << is11bai(s) << endl;

	cout << t << ":" << is3bai(t) << endl;
	cout << t << ":" << is9bai(t) << endl;
	cout << t << ":" << is11bai(t) << endl;

	cout << u << ":" << is3bai(u) << endl;
	cout << u << ":" << is9bai(u) << endl;
	cout << u << ":" << is11bai(u) << endl;

	return 0;
}