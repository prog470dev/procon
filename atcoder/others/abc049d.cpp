/*
par[i]を見るだけでは本当のrootはわからない。
（unite()の中で適用されていないものもある。）
→ 全てに対してfind()を使って出力する。
*/


#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define MAX_N 200005

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

  int N, K, L;
  cin>>N>>K>>L;

  UnionFind ufl(N);
  UnionFind ufr(N);

  for(int i=0; i<K; i++){
    int x, y;
    cin>>x>>y;
    ufl.unite(x-1,y-1);
  }
  for(int i=0; i<L; i++){
    int x, y;
    cin>>x>>y;
    ufr.unite(x-1,y-1);
  }

  map< pair<int, int>, int > m;

  for(int i=0; i<N; i++){
    m[make_pair(ufl.find(i), ufr.find(i))]++;
  }

  for(int i=0; i<N; i++){
    if(i != 0) cout<<" ";
    cout<<m[make_pair(ufl.find(i), ufr.find(i))];
  }
  cout<<endl;

  return 0;
}
