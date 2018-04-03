/**
 * クラスカル法
 *  - 概要
 *      - 最小全域木とその辺の重みの合計を求める.
 *      - 辺を、コストの小さい方から見ていき、両端のノードを確定済み集合に加えていく。
 *  - 時間計算量
 *      - O(|E|log|V|)
 * - メモ
 *      - 内部的にUnionFindを使用
*/

#include <iostream>
#include <vector>
#include <utility>

#define REP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

/*==================================================*/
const int NODE_SIZE = 101010;

int N; //グラフのノードの数
int M; //グラフのエッジ数
vector<pair<int, pair<int, int>>> edge; // < 辺のコスト, <node0, node1> >

/*==================================================*/
//UnionFindの定義
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

//ここからクラスカル方の本体
int kruskal(){
  int ret;
  sort(edge.begin(), edge.end());
  UnionFind uf(N);
  ret = 0;
  for(int i=0; i<M; i++){
    int node0=edge[i].second.first, node1=edge[i].second.second;
    int cost = edge[i].first;
    if(uf.same(node0,node1)) continue;
    uf.unite(node0,node1);
    ret += cost;
  }

  return ret;
}

/*==================================================*/
int main(){

  //グラフ作成
  cin>>N>>M;
  for(int i=0; i<M; i++){
    int a,b,c;
    cin>>a>>b>>c;
    edge.push_back(make_pair(c,make_pair(a,b)));
  }

  int ans = kruskal();
    
	return 0;
}