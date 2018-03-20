/*
Union-Find
使用例：
  //実体化 (N:ノードの最大個数)
  UnionFind uf(N);
  //ノードxとノードyを同じグループに結合
  uf.unite(x, y);
  //ノードxとノードyを同じグループかどうか(true or false)
  uf.same(x, y);
*/

using namespace std;

const int MAX_N = 100010;

struct UnionFind{
    int par[MAX_N];
    int deph[MAX_N];
    UnionFind(int n){
        fill(par, par + MAX_N, -1);
        for(int i=0; i<n; i++){
            par[i] = i;
            deph[i] = 0;
        }
    }
    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(deph[x] < deph[y]){
            par[x] = par[y];
        }else{
            par[y] = par[x];
            if(deph[x] == deph[y]) deph[x]++;
        }
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};
