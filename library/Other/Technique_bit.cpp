/* bit関連

・ビット反転：各ビットの0/1を反転
	~data

・ビット論理和：一方が1なら1
	data1 | data2

・ビット論理積：両方1なら1
	data1 & data2

・ビット排他的論理和：片方のみが1なら1
	data1 ^ data2

・左ビットシフト：左にn桁ずらす(=整数なら2のn乗倍)
	data << n

・右ビットシフト：右にn桁ずらす(=整数なら2の1/n乗倍)
	data >> n

・1になっている1番下の桁を取得(-data = data+1)
	data & (-data)

・1になっている1番下の桁を0にする
	data &= data-1

・1になっているbitの数を返す
	__builtin_popcount(unsigned int)

ex) __builtin_popcount(10) = 2


・XORswap：変数a, bの値を一時変数を用意せずに入れ替え
void XORswap(int *a, int *b) {
	// aとbのポインタが同じだと値が0になる
	if (a != b) {
		*b ^= *a;
		*a ^= *b;
		*b ^= *a;
	}
}

// 使い方
int main(){
	int a = 3, b = 5;
	XORswap(a, b);
	cout<<a<<" "<<b<<endl;
	return 0;
}


・組み合わせ列挙(ビットで)：n個のビットのうち立っているビットがk個の組み合わせ

typedef unsigned long long ull;
// 全ビットを出力
void print_bit(ull S, int n = 64) {
	for (int i = n - 1; i >= 0; i--) {
		if (S >> i & 1) cout << 1;
		else cout << 0;
	}
	cout << endl;
}

// 組み合わせを求める
void subset_combination(int n, int k) {
	ull S = (1ULL << k) - 1ULL;
	ull E = ~((1ULL << n) - 1ULL);
	while (!(S & E)) {
		print_bit(S, n);
		ull smallest = S & -S;
		ull ripple = S + smallest;
		ull nsmallest = ripple & -ripple;
		S = ripple | (((nsmallest / smallest) >> 1) - 1);
	}
}

// 使い方
subset_combination(3, 2)
----------------------
011
101
110
----------------------


*/
