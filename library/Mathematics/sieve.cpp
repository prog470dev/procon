#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

/*
エラトステネスの篩

引数  ：①int n
        ②int n

返り値：①なし(グローバルで配列宣言、trueかfalse)
        ②vector<int>(素数のみで構成)

概要  ：与えられた区間(0～n)に対する素数を求める
  ①グローバルで宣言されている配列isPrimeに対し、
　  素数ならtrue、そうでないならfalse
  ②0～n内の素数をvectorで持ち、返り値とする

制約  ：n <= 10^6

計算量：Ｏ(nloglogn)

*/

/*==================================================*/
bool isPrime[1000010]; // n<1000010

/*==================================================*/
// isPrime[0~n]で素数のものだけtrueにする
void hurui(int n) {
	// 初期化
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < n + 1; i++) isPrime[i] = true;

	for (int i = 2; i*i <= n; i++) {  // iがsqrt(n)となるまで繰り返す
		for (int j = i * 2; j < n + 1; j += i) {
			isPrime[j] = false;       // 素数でない
		}
	}
	return;
}

// 素数の集合(vector<int>)を返す
vector<int> hurui_v(int n) {
	vector<int> v;
	bool *isPrime_v;
	isPrime_v = new bool[n + 1]; // 処理用のメモリ確保

	// 初期化
	isPrime_v[0] = isPrime_v[1] = false;
	for (int i = 2; i < n + 1; i++) isPrime_v[i] = true;

	// isPrime[0~n]で素数のものだけtrueにする
	for (int i = 2; i*i <= n; i++) {
		for (int j = i * 2; j < n + 1; j += i) {
			isPrime_v[j] = false;
		}
	}

	// 素数のみ追加
	for (int i = 0; i < n + 1; i++) {
		if (isPrime_v[i]) v.push_back(i);
	}

	delete[] isPrime_v; //メモリ解放
	return v;
}

/*==================================================*/

int main() {
	int n;
	cin >> n;

	// 配列形式
	hurui(n);
	REP(i, 0, n + 1) cout << i << "=" << isPrime[i] << endl;

	// vector形式
	vector<int> prime = hurui_v(n);
	for (auto itr : prime) cout << itr << endl;

	return 0;
}