/*
最大２部マッチング
O(V^2*E)
概要：
　二部グラフに対して、各辺のキャパシティを１とした
　最大流問題として見る。
*/

//最大流に関する定義
template<class V> struct MaxFlow {
    struct edge { int to, reve; V cap; edge(int t, int r, V c) : to(t), reve(r), cap(c) {} };
    int MV; vector< vector<edge> > E; vector<int> itr, lev;
    MaxFlow(int n) { init(n); } MaxFlow() { }
    void init(int n) { MV = n; itr = vector<int>(MV), lev = vector<int>(MV); E = vector< vector<edge> >(MV); }
    void add_edge(int x, int y, V cap, bool undir = false) {
        E[x].push_back(edge(y, (int)E[y].size(), cap));
        E[y].push_back(edge(x, (int)E[x].size() - 1, undir ? cap : 0));
    }
    void bfs(int cur) {
        REP(i, 0, MV) lev[i] = -1; queue<int> q; lev[cur] = 0; q.push(cur);
        while (q.size()) {
            int v = q.front(); q.pop();
            for (auto e : E[v]) if (e.cap>0 && lev[e.to]<0) lev[e.to] = lev[v] + 1, q.push(e.to);
        }
    }
    V dfs(int from, int to, V cf) {
        if (from == to) return cf;
        for (; itr[from]<E[from].size(); itr[from]++) {
            edge* e = &E[from][itr[from]]; if (e->cap>0 && lev[from]<lev[e->to]) {
                V f = dfs(e->to, to, min(cf, e->cap));
                if (f>0) { e->cap -= f; E[e->to][e->reve].cap += f; return f; }
            }
        } return 0;
    }
    V maxflow(int from, int to) {
        V fl = 0, tf;
        while (1) {
            bfs(from); if (lev[to]<0) return fl;
            REP(i, 0, MV) itr[i] = 0; while ((tf = dfs(from, to, numeric_limits<V>::max()))>0) fl += tf;
        }
    }
};


// 二部最大マッチング
struct BipartiteMatching {
    int N, M; MaxFlow<int> mf;
    //コンストラクタ(引数は各集合のノード数)
    BipartiteMatching(int n, int m) : N(n), M(m) { mf.init(n + m + 2); }
    //辺を作成してグラフをつくる（引数は各集合内で一意なノード識別番号）
    void add_edge(int a, int b) { mf.add_edge(a, N + b, 1); }
    //最大マッチング数を返す
    int match() { REP(a, 0, N) mf.add_edge(N + M, a, 1); REP(b, 0, M) mf.add_edge(N + b, N + M + 1, 1);
        return mf.maxflow(N + M, N + M + 1); }
    // マッチング相手を返す(無いなら-1)
    int whois(int a) { for (auto e : mf.E[a]) if (e.cap == 0) return e.to - N; return -1; }
};

/*
サンプル：
  ・それぞれ整数が設定されたノードの集合A,Bがある。
  ・A、Bそれぞれから１つずつ選んだ整数が、
   １より大きな公約数を持つとき、その２つはマッチングする。
*/
int main() {
  int M, N, B[110], R[110];
  while(cin>>M>>N){
    REP(i,0,M) cin>>B[i];
    REP(i,0,N) cin>>R[i];
    BipartiteMatching bm(M, N);
    REP(b,0,M){
      REP(r,0,N){
        if(__gcd(B[b],R[r]) != 1) bm.add_edge(b, r);
      }
    }
    cout<<bm.match()<<endl;
  }
  return 0;
}
