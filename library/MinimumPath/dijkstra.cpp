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

const ll LLINF = 1e18;
const ll NODE_SIZE = 10101;

ll N;  //グラフのノードの数
ll M;  //グラフの辺の数
vector<pair<ll, ll>> edge[NODE_SIZE];   //<ノード, 距離>
ll d[NODE_SIZE];   //始点ノードからノードiへの最短距離
ll start;  //開始ノード番号

/*==================================================*/

//ダイクストラ法
void dijkstra() {
    priority_queue< pair<ll, ll> > PQ;  //<(-1)*最短距離, ノード番号>

    REP(i,0,N) d[i] = LLINF;
    d[start] = 0;
    PQ.push(make_pair(0,start));  //開始ノードを0とする。

    while(!PQ.empty()){
        ll curCost = -PQ.top().first;
        ll curNode = PQ.top().second;
        PQ.pop();

        if(d[curNode] < curCost) continue;
        d[curNode] = curCost;

        REP(i,0,edge[curNode].size()){
            ll nextNode = edge[curNode][i].first;
            ll addCost = edge[curNode][i].second;

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
    start = 0;  //開始ノードを設定
    dijkstra(); //実行後:d[i]にstartからiへの最短距離

    return 0;
}