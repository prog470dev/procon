/*
素因数分解

概要：与えられた整数の素因数とその数をvectorで持ち、返り値とする

返り値：vector<pair<int, int>> (first：素因数, second：素因数の数)

*/

vector<pair<int, int>> prime_factor(int n) {
	vector<pair<int, int>> vp;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			vp.emplace_back(i, 0);
			do {
				vp[vp.size() - 1].second++;
				n /= i;
			} while (n%i == 0);
		}
	}
	if (n != 1) vp.emplace_back(n, 1);
	return vp;
}
