//TODO: 配列も含めた構造体なりクラスにまとめたほうが良いか？

/**
 * Binary Indexed Tree (BIT)
 *  - 概要
 *      - クエリに対して連結成分を作成
 *  - 時間計算量
 *      - add:  aの要素をwに更新する O(log N)
 * 		- sum:  aの合計を返す		O(log N)
 * - メモ
 * 		- 変更・答えのクエリが多いときに有効
 * 		- 添え字に注意
*/

#include <iostream>

using namespace std;

/*==================================================*/
int N;
int bit[1000010];	//数列の要素

int bit2d[1010][1010];

/*==================================================*/

//TODO: UnitonFindのように構造体で定義

/* 1次元のBIT (添え字0からN-1) */
void add(int a, int w) {	//a番目の要素にwを加算
	for (int x = a; x < N; x |= x + 1) 	bit[x] += w;
}
int sum(int a) {
	int ret = 0;
	for (int x = a - 1; x >= 0; x = (x & (x + 1)) - 1) {
	ret += bit[x];
 	return ret;
}


/* 1次元のBIT (添え字1からN) */
void add(int a, int w) {	//a番目の要素にwを加算
	for (int x = a; x <= N; x += x & -x) bit[x] += w;
}
int sum(int a) {//aの合計を返す
	int ret = 0;
	for (int x = a; x > 0; x -= x & -x) ret += bit[x];
 	return ret;
}


/* 2次元のBIT (添え字1からN) */
void add(int a, int b, int w) {	//要素(a,b)にwを加算
	for (int x = a; x <= M; x += x & -x){
		for (int y = b; y <= N; y += y & -y){
			bit2d[x][y] += w;
		}
	}	
}
int sum(int a, int b){
	int ret = 0;
	for (int x = a; x > 0; x -= x & -x)
		for (int y = b; y > 0; y -= y & -y)
			ret += bit2d[x][y];
	return ret;
}

/*==================================================*/
int main(){

	//１次元 (1始まり)
	int i=0, j=0;
	add(i, 1);	//i番目の数列にiを加算
	sum(i);	//0番目からi番目までの要素の和

	//2次元
	add(i, j, 1);	//(i,j)番目の数列にiを加算
	sum(i, j);	//(0,0)番目から(i,j)番目までの要素の和
	
	return 0;
}