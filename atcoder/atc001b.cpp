#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>

#define MAX_N 100000

using namespace std;

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

int main() {
  int N, Q;
  cin>>N>>Q;

  UnionFind uf(N);

  for(int i=0; i<Q; i++){
    int p, a, b;
    cin>>p>>a>>b;
    if(p == 0){
      uf.unite(a, b);
    }else{
      if(uf.same(a, b)) cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
    }
  }

  return 0;
}
