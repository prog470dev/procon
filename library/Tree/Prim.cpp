/**
 * プリム法
 *  - 概要
 *      - 最小全域木とその辺の重みの合計を求める.
 *  - 時間計算量
 *      O(|V|log|E|)
 * - メモ
 * 		- 変更・答えのクエリが多いときに有効
 * 		- 添え字に注意
*/

#include <iostream>
#include <queue>

#define REP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

const int INF = 1e9;

/*==================================================*/
const int NODE_SIZE = 101010;

int N; //グラフのノードの数
int M; //グラフのエッジ数
int edge[NODE_SIZE][NODE_SIZE]; //ノードaとbの距離 (繋がっていなければINF)

/*==================================================*/


int prim(){
  bool used[1000];  //すでに確定済み集合に入っているか
  int ret;          //最小全域木の辺のコストの総和
  priority_queue<pair<int, int> > PQ; //<コスト, 行き先ノード>

  for(int i=0; i<NODE_SIZE; i++){
    used[i] = false;
  }

  ret = 0;  //最小全域木の辺の総数
  PQ.push(make_pair(0,0));

  while(!PQ.empty()){
    int curNode = PQ.top().first;
    int curCost = -PQ.top().second;
    PQ.pop();
    if(used[curNode]) continue;
    used[curNode] = true;
    ret += curCost;
    for(int nextNode=0; nextNode<NODE_SIZE; nextNode++){
      if(edge[curNode][nextNode] != INF) PQ.push(make_pair(-edge[curNode][nextNode],nextNode));
    }
  }

  return ret;
}


/*==================================================*/
int main(){
	
  //グラフ作成
  REP(i,0,NODE_SIZE) REP(j,0,NODE_SIZE) edge[i][j] = INF;
  cin>>N>>M;
  REP(i,0,M){
    int s,t,w;
    cin>>s>>t>>w;
    edge[s][t] = edge[t][s] = w;
  }

  int ans = prim();
  
	return 0;
}