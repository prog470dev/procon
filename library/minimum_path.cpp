/*
ワーシャル・フロイト法
O(N^3)
概要：
  グラフにおいて、任意の２ノード間の最短距離を求める。
使用例：
  N: グラフのノードの数
  M: グラフの辺の数
  edge[a][b]: ノードaとbの距離 (繋がっていなければINF)
補足:
  WF実行後、自分自身へのパスが一つでも負になっていれば、負の経路が存在
*/

int N,M;
long long edge[1000][1000];

//入力・初期化
cin>>N>>M;
REP(i,0,N){
  REP(j,0,N){
    if(i==j) edge[i][j] = 0;
    else edge[i][j] = LLINF;
  }
}
REP(i,0,M){
  int a,b;
  long long c;
  cin>>a>>b>>c;
  edge[a][b] = edge[b][a] = c;
}

REP(k,0,N){
  REP(i,0,N){
    if(edge[i][k] == INF) continue;
    REP(j,0,N){
      if(edge[k][j] == INF) continue;
      edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
    }
  }
}


/*
ダイクストラ法
O(|E|log|V|)
概要：
  グラフにおいて、始点ノードから各ノードへの最短距離を求める。
使用例：
  N: グラフのノードの数
  M: グラフの辺の数
  edge[a][b]: <ノード, 距離>
  d[i]: 始点ノードからノードiへの最短距離
  visite[i]: ノードiにすでに訪れているかどうか
*/
int N, M;
vector<pair<int,int> > edge[100010];
int d[100010];
int visited[100010];

//入力処理・初期化
cin>>N;
REP(i,0,N){
  d[i] = INF;
  visited[i] = false;
}
REP(i,0,N){
  int a,k,b,c;
  cin>>a>>k;
  REP(j,0,k){
    cin>>b>>c;
    edge[a].push_back(make_pair(b,c));
  }
}

REP(i,0,N) d[i] = INF;
priority_queue< pair<int, int> > PQ;  //<(-1)*最短距離, ノード番号>
PQ.push(make_pair(0,0));  //開始ノードを0とする。
d[0] = 0;

while(!PQ.empty()){
  int curCost = -PQ.top().F;
  int curNode = PQ.top().S;
  PQ.pop();
  if(d[curNode] < curCost) continue;
  visited[curNode] = true;
  REP(i,0,edge[curNode].size()){
    int nextNode = edge[curNode][i].F;
    if(visited[nextNode]) continue;
    if(d[nextNode] > d[curNode] + edge[curNode][i].S){
      d[nextNode] = d[curNode] + edge[curNode][i].S;
      PQ.push(make_pair(-d[nextNode], nextNode));
    }
  }
}


/*
ベルマンフォード法
O(|E||V|)
概要：
  グラフにおいて、始点ノードから各ノードへの最短距離を求める。
使用例：
  N: グラフのノードの数
  M: グラフの辺の数
  edge: <コスト, <ノード, 距離>>
  d[i]: 始点ノードからノードiへの最短距離
  visite[i]: ノードiにすでに訪れているかどうか
補足:
    負の経路がなければ更新はN-1回でストップ
    N回目の更新があれば、負の経路が存在
*/

int N, M;
vector<pair<int, pair<int,int> > > edge;
int d[100010];

//入力・初期化
cin>>N>>M;
REP(i,0,N) d[i] = INF;
d[0] = 0;

REP(i,0,M){
  int a,b;
  long long c;
  cin>>a>>b>>c;
  edge.push_back(make_pair(c, make_pair(a,b)));
  //edge.push_back(make_pair(c, make_pair(b,a)));
  /*有向グラフの為*/
}

REP(i,0,N-1){
  bool update = false;
  REP(j,0,edge.size()){
    int from = edge[j].S.F;
    int to = edge[j].S.S;
    if(d[from] != INF && d[to] > d[from] + edge[j].F){
      d[to] = d[from] + edge[j].F;
      update = true;
    }
  }
  if(!update) break;
}
