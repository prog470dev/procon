/**
 * ダイクストラ法
 *  - 概要
 *      - 開始ノードから任意のノードへの最短距離を計算
 *  - 時間計算量
 *      - O( |E|log|V| )
 *  - 探索対象
 *      - グラフ (vector)
 *  - MEMO
 *      - [注意] 負の辺が含まれる場合は使えない -> ベルマンフォード法を使う
*/

#include <iostream>
# include <utility> //for pair
#include <vector>
#include <queue>

#define REP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

const int INF = 1e9;
const int NODE_SIZE = 10101;

int N;  //グラフのノードの数
int M;  //グラフの辺の数
vector<pair<int, int>> edge[NODE_SIZE];   //<ノード, 距離>
int d[NODE_SIZE];   //始点ノードからノードiへの最短距離
int start;  //開始ノード番号

/*==================================================*/

//ダイクストラ法
void dijkstra() {
    priority_queue< pair<int, int> > PQ;  //<(-1)*最短距離, ノード番号>
    
    PQ.push(make_pair(0,start));  //開始ノードを0とする。

    while(!PQ.empty()){
        int curCost = -PQ.top().first;
        int curNode = PQ.top().second;
        PQ.pop();

        if(d[curNode] <= curCost) continue;
        d[curNode] = curCost;
        
        REP(i,0,edge[curNode].size()){
            int nextNode = edge[curNode][i].first;
            int addCost = edge[curNode][i].second;

            if(d[nextNode] > d[curNode] + addCost){
                d[nextNode] = d[curNode] + addCost;
                PQ.push(make_pair(-d[nextNode], nextNode));
            }
        }  
    }
}


/*==================================================*/
int maint(){

    //ここでグラフの生成
    REP(i,0,N) d[i] = INF;
    start = 0;
    dijkstra();

    return 0;
}