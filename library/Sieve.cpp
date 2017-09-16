/*
エラトステネスの篩

返り値：①なし(グローバルで配列宣言、trueかfalse)②vector<int>(素数のみで構成)

概要：与えられた区間(0～n)に対する素数を求める
	①グローバルで宣言されている配列isPrimeに対し、
	　素数ならtrue、そうでないならfalse
	②0～n内の素数をvectorで持ち、返り値とする

制約：n <= 10^6

*/

bool isPrime[1000010]; // n<1000010
void hurui(int n) {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < n + 1; i++) isPrime[i] = true;

	for (int i = 2; i*i <= n; i++) {
		for (int j = i * 2; j < n + 1; j += i) {
			isPrime[j] = false;
		}
	}
	return;
}

vector<int> hurui_v(int n) {
	vector<int> v;
	bool *isPrime;
	isPrime = new bool[n + 1];

	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < n + 1; i++) isPrime[i] = true;

	for (int i = 2; i*i <= n; i++) {
		for (int j = i * 2; j < n + 1; j += i) {
			isPrime[j] = false;
		}
	}
	for (int i = 0; i < n + 1; i++) {
		if (isPrime[i]) v.push_back(i);
	}

	delete[] isPrime;
	return v;
}
