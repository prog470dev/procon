/**
 * ベルマン・フォード法
 *  - 時間計算量
 *      - O( |E||V| )
 *  - 探索対象
 *      - グラフ (vector)
 *  - MEMO
 *      - 負の経路がなければ更新は(|V|-1)回でストップ
 *      - |V|回目の更新があれば、負の経路が存在
*/

#include <iostream>
#include <utility> //for pair
#include <vector>
#include <queue>

#define REP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

const int INF = 1e9;
const int EDGE_SIZE = 10101;

int N;  //グラフのノードの数
int M;  //グラフの辺の数
vector< pair<int, pair<int, int>> > edge[EDGE_SIZE];   //辺情報　<コスト, <formノード, toノード>>
int d[EDGE_SIZE];   //始点ノードからノードiへの最短距離
int visite[EDGE_SIZE];   //ノードiにすでに訪れているかどうか
int start;  //開始ノード番号

bool negCloCir = false; //負の閉路があるかどうかのフラグ

/*==================================================*/

//ベルマン・フォード法
void bellman_ford() {
  REP(i,0,N-1){
    bool update = false;
    REP(j,0,edge.size()){
      int from = edge[j].second.first;
      int to = edge[j].second.second;
      if(d[from] != INF && d[to] > d[from] + edge[j].F){
        d[to] = d[from] + edge[j].F;
        update = true;
      }
    }
    if(!update) break;
  }
  if(update) negCloCir = true;  //負の閉路が存在
}


/*==================================================*/
int main(){
  
  //ここでグラフの生成
  REP(i,0,N) d[i] = INF;
  d[start] = 0;
  bellman_ford();

  if(negCloCir){
    //負の閉路がある場合の処理
  }
  
}