/**
 * Union-Find-QFW
 *  - 概要
 *      - クエリに対して連結成分を作成
 * 		- ノードが持っていたアイテムについても考慮
 *  - 時間計算量
 *      - O( log|V|以下 )
*/

#include <iostream>    
#include <algorithm> 
#include <vector>

using namespace std;

/*==================================================*/
struct UnionFind_QFW {
	vector<int> i2g;  // i2g[i]:アイテムiの所属するグループの番号
	/* アイテムの種類を変えたいときは下を変更 */
	vector<vector<int>> g2i; // g2i[g]:グループgに所属するアイテムたち

	UnionFind_QFW(int n) {
		i2g.resize(n);
		g2i.resize(n);
		for (int i = 0; i < n; i++) {
			i2g[i] = i;
			g2i[i].assign(1, i); // アイテムiを１つ割り当てる
		}
	}

	// 同じグループに所属しているか
	bool same(int ix, int iy) {
		return i2g[ix] == i2g[iy];
	}

	// xの所属するグループとyの所属するグループを結合
	void merge(int ix, int iy) {
		if (same(ix, iy)) return; // 同じグループなら何もしない

		// グループxのアイテム数 > グループyのアイテム数  となるように(※ 一般的なマージテク)
		if (g2i[i2g[ix]].size() < g2i[i2g[iy]].size()) {
			swap(ix, iy);
		}

		// gxの要素数 > gyの要素数
		int gx = i2g[ix];
		int gy = i2g[iy];
		for (int j : g2i[gy]) {
			i2g[j] = gx;
		}

		g2i[gx].insert(g2i[gx].end(), g2i[gy].begin(), g2i[gy].end()); // グループの結合
		g2i[gy].clear();
	}
};

/*==================================================*/
int main(){
	
	int N;	//アイテム数
	int items[3];	//アイテムiはグループ[i]に所属

	UnionFind_QFW ufq(N);

	int ix = 0, iy = 1;
	
	// ixの所属するグループとiyの所属するグループを同じグループに結合
	ufq.merge(ix, iy);
	// アイテムixとアイテムiyが同じグループかどうか(true or false)
	ufq.same(ix, iy);

	return 0;
}