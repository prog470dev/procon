/*
Union-Find
使用例：
//実体化 (N:ノードの最大個数)
UnionFind uf(N);

// xの親ノード番号を返す
uf.find(x)

// ノードxとノードyを同じグループに結合
uf.unite(x, y);

// ノードxとノードyが同じグループかどうか(true or false)
uf.same(x, y);
*/
const int MAX_N = 100010;
struct UnionFind {
	int par[MAX_N];    // 親ノードの番号
	int deph[MAX_N];   // ノードの深さ

	/* ↑以外に持っておくデータ
	// 例)木であるかどうか(bool値)を持つ場合
	// bool istree[MAX_N];

	*/

	UnionFind(int n) {
		fill(par, par + MAX_N, -1);  // -1で初期化
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
		}
		else {
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
		}
		else {
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