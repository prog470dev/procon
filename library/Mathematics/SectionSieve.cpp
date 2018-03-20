/*
区間篩

返り値：vector(素数のみで構成)

概要：与えられた区間(L～R)に対する素数を求める
	　まず、sqrt(R)までの素数を求め、その素数のみを用いてL～R区間のみの篩を行う

制約：R<=10^12, R-L<=10^6

 */

vector<long long> kukan_hurui_v(long long l, long long r) {
	vector<long long> v, ans;

	// sqrt(r)までの素数群vを求める
	bool *isPrime;
	long long n = (long long)sqrt(r) + 1;
	isPrime = new bool[n + 1];

	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= n; i++) isPrime[i] = true;

	for (int i = 2; i*i <= n; i++) {
		for (int j = i * 2; j <= n; j += i) {
			isPrime[j] = false;
		}
	}
	for (int i = 0; i <= n; i++) {
		if (isPrime[i]) v.push_back(i);
	}
	delete[] isPrime;

	// vを用いてL～R間を篩にかける
	bool *Prime;
	Prime = new bool[r - l + 1];
	for (long long i = 0; i < r - l + 1; i++) Prime[i] = true;

	for (long long i = 0; i < v.size(); i++) {
		long long idx;
		for (long long j = 0; j <= r - l; j++) {
			if ((j + l) % v[i] == 0) {
				idx = j;
				break;
			}
		}

		for (long long j = idx; j <= r - l; j += v[i]) {
			Prime[j] = false;
		}
	}

	for (long long i = 0; i <= r - l; i++) {
		if (Prime[i]) ans.push_back(i + l);
	}

	delete[] Prime;
	return ans;
}
