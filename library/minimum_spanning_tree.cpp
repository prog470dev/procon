/*
プリム法
O(O(|V|log|E|))
概要：
　確定済みノード集合にの端点とつながっている未確定ノードを、
　コストが小さいものから集合に加えていく。
使用例：
  N: グラフのノードの数
  M: グラフの辺の数
  edge[a][b]: ノードaとbの距離 (繋がっていなければINF)
*/

int edge[1000][1000];
REP(i,0,1000) REP(j,0,1000) edge[i][j] = INF;

bool used[1000];  //すでに確定済み集合に入っているか
int res;          //最小全域木の辺のコストの総和
priority_queue<pair<int, int> > PQ; //<コスト, 行き先ノード>

REP(i,0,100000){
  used[i] = false;
}

//入力処理
int V,E,s,t,w;
cin>>V>>E;
REP(i,0,E){
  cin>>s>>t>>w;
  edge[s][t] = edge[t][s] = w;
}

res = 0;  //最小全域木の辺の総数
PQ.push(make_pair(0,0));

while(!PQ.empty()){
  int curNode = PQ.top().S;
  int curCost = -PQ.top().F;
  PQ.pop();
  if(used[curNode]) continue;
  used[curNode] = true;
  res += curCost;
  REP(nextNode,0,100000){
    if(edge[curNode][nextNode] != INF) PQ.push(make_pair(-edge[curNode][nextNode],nextNode));
  }
}



/*
クラスカル法
O(O(|E|log|V|))
概要：
  辺を、コストの小さい方から見ていき、
  両端のノードを確定済み集合に加えていく。
使用例：
  N: グラフのノードの数
  M: グラフの辺の数
  edge: < 辺のコスト, <node0, node1> >
補足:
  ・UnionFindが必要
  ・最大ノード数に10^5を設定
*/

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
int N, M;
int res;
vector< pair< int,pair<int,int> > > edge;

//入力処理
cin>>N>>M;
REP(i,0,M){
int a,b,c;
cin>>a>>b>>c;
  edge.push_back(make_pair(c,make_pair(a,b)));
}

sort(edge.begin(), edge.end());
UnionFind uf(N);

res = 0;
REP(i,0,M){
  int node0=edge[i].S.F, node1=edge[i].S.S;
  int cost = edge[i].F;
  if(uf.same(node0,node1)) continue;
  uf.unite(node0,node1);
  res += cost;
}
