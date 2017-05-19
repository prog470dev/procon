/*
・vector.size()の返り値は、vector<型名>::size_type型なので、
　v.size() - 1などと、キャストせずに計算することは許されない。
　ただし、v.size() > 0のときは上手く行ってしまう。０だとだめ。
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define MAX_N 1000

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

  int n;
  bool f[55][35];

  //test
  vector<int> vec;

while(1){
  for(int i=0; i<55; i++){
    for(int j=0; j<35; j++){
      f[i][j] = false;
    }
  }

  cin>>n;
  if(n == 0) break;

  for(int i=0; i<n; i++){
    int t;
    cin>>t;
    if(t == 0) break;
    for(int j=0; j<t; j++){
      int tt;
      cin>>tt;
      f[i][tt] = true;
    }
  }

  UnionFind uf(n);

  int ans = 1;
  for(int i=1; i<=30; i++){
    vector<int> v;
    for(int j=0; j<n; j++){
      if(f[j][i]) v.push_back(j);
    }
    for(int k = 0; k<(int)v.size()-1; k++){
        uf.unite(v[k],v[k+1]);
    }
    set<int> s;
    for(int k =0; k<n; k++){
      s.insert(uf.par[k]);
    }
    if(s.size() == 1) break;
    ans++;
  }

  if(ans == 31) vec.push_back(-1);//cout<<-1<<endl;
  else vec.push_back(ans);//cout<<ans<<endl;

}

  for(int l=0; l<vec.size(); l++) cout<<vec[l]<<endl;

  return 0;
}
