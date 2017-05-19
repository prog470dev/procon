/*

;example in main function

UnionFind uf(N);
unite(x, y);
same(x, y);

*/

#define MAX_N 1e9

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
