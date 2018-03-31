/*
プリム法
O(O(|V|log|E|))
概要：

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

/*==================================================*/
int main(){
	
	return 0;
}