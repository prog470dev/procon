/*
 * Lowest Common Ancestor (最小共通祖先)
 * 木の頂点 a, bに一番近い親ノードを求める O(log N)
 *
 * よくある使い方
 * 頂点a, bの距離dist(a, b)を求める
 * dist(a,b) = dist(root, a) + dist(root, b) - 2 * dist(root, LCA(a,b))
 *
 */
#include <iostream>
#include <vector>
#define REP(i, n, N) for(ll i = (n); i < (N); i++)
using namespace std;
typedef long long ll;

int N;
vector<int> E[101010];
int U[101010];

class LCA {
public:
	int NV, logNV;
	vector<int> D;
	vector<vector<int> > P;

	LCA(int N) {
		NV = N;
		logNV = 0;
		while (NV > (1LL << logNV)) logNV++;
		D = vector<int>(NV);
		P = vector<vector<int>>(logNV, vector<int>(NV));
		dfs(0, -1, 0);
		build();
	}

	void dfs(int v, int par, int d) {
		D[v] = d;
		P[0][v] = par;
		for (int i : E[v]) if (i != par) dfs(i, v, d + 1);
	}

	void build() {
		REP(k, 0, logNV - 1) {
			REP(v, 0, NV) {
				if (P[k][v] < 0)
					P[k + 1][v] = -1;
				else
					P[k + 1][v] = P[k][P[k][v]];
			}
		}
	}

	int query(int u, int v) {
		if (D[u] > D[v]) swap(u, v);
		REP(k, 0, logNV) if ((D[v] - D[u]) >> k & 1) v = P[k][v];
		if (u == v) return u;

		for (int k = logNV - 1; k >= 0; k--) {
			if (P[k][u] != P[k][v]) {
				u = P[k][u];
				v = P[k][v];
			}
		}
		return P[0][u];
	}
};


//-----------------------------------------------------------------
int main() {
	scanf("%d", &N);
	REP(i, 0, N - 1) {
		int a, b;
		scanf("%d %d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}

	LCA lca(N); //LCA構築

	int M;
	scanf("%d", &M);
	ll ans = 0;
	REP(i, 0, M) {
		int a, b;
		scanf("%d %d", &a, &b);

		int p = lca.query(a, b); // LCAを求める
		ans += (sum[a] + sum[b] - sum[p] * 2); // 2点間の距離の総和を求めてみる
	}
	printf("%lld\n", ans);
}