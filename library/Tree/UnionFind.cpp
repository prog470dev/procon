/**
 * Union-Find
 *  - 概要
 *      - クエリに対して連結成分を作成
 *  - 時間計算量
 *      - 各クエリに対して O( log|V|以下 )
*/

#include <iostream>     // std::cout
#include <algorithm>    // std::fill

using namespace std;

/*==================================================*/
const int MAX_N = 100010;

struct UnionFind {
	int par[MAX_N];    // 親ノードの番号
	int deph[MAX_N];   // ノードの深さ

	/* 上以外に持っておくデータ
	// 例)木であるかどうか(bool値)を持つ場合
	// bool istree[MAX_N];
	*/

	UnionFind(int n) {
		fill(par, par + MAX_N, -1);
		for (int i = 0; i<n; i++) {
			par[i] = i;
			deph[i] = 0;

			/* 持っておくデータにおいて初期化が必要な場合
			// istree[i] = true;
			*/
		}
	}

	int find(int x) {
		if (par[x] == x) {
			return x;
		} else {
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			/* 同じグループに属しているときの処理
			// istree = false;
			*/
			return;
		} 
		if (deph[x] < deph[y]) {
			par[x] = par[y];
			/* ルートをyとする時の処理
			*/
		} else {
			par[y] = par[x];
			if (deph[x] == deph[y]) deph[x]++;
			/* ルートをxとする時の処理
			*/
		}
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

/*==================================================*/
int main(){
	int N = 100;	//ノード数
  	UnionFind uf(N);	//実体化 (N:ノードの最大個数)
  	
	int x = 3, y = 5;	//クエリの対象ノード
	uf.unite(x, y);	//ノードxとノードyを同じグループに結合
  	uf.same(x, y);	//ノードxとノードyを同じグループかどうか(true or false)
	
	return 0;
}