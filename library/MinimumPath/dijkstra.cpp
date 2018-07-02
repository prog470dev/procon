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
 *      - [最小経路のルート(route)が知りたい時] コメントで ** となっているところをコントアウト
*/

#include <iostream>
#include <algorithm>
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
//ll rev[NODE_SIZE]; //一個前のノード番号を覚えておく配列 **
/*==================================================*/

//ダイクストラ法
void dijkstra() {
    priority_queue<pair<ll, ll> > PQ;  //<(-1)*最短距離, ノード番号>

    REP(i, 0, N) d[i] = LLINF;
    d[start] = 0;
    PQ.push(make_pair(0, start));  //開始ノードを0とする。

    while (!PQ.empty()) {
        ll curCost = -PQ.top().first;
        ll curNode = PQ.top().second;
        PQ.pop();

        if (d[curNode] < curCost) continue;
        d[curNode] = curCost;

        REP(i, 0, edge[curNode].size()) {
            ll nextNode = edge[curNode][i].first;
            ll addCost = edge[curNode][i].second;

            if (d[nextNode] > d[curNode] + addCost) {
                d[nextNode] = d[curNode] + addCost;
                //rev[nextNode] = curNode; // ** 最短経路のルートが欲しい場合
                PQ.push(make_pair(-d[nextNode], nextNode));
            }
        }
    }
}

//最小経路上のノードの取得
vector<ll> check_route(ll goal) {
    ll curNode;
    ll preNode = goal;
    vector<ll> route;
    route.push_back(goal);
    while (preNode != start) {
        curNode = preNode;
        preNode = rev[curNode];
        route.push_back(preNode);
    }
    reverse(route.begin(), route.end());

    return route;
}

int main() {
    cin >> N >> M;
    REP(i, 0, M) {
        cin >> A >> B >> C;
        edge[A].emplace_back(B, C);
        edge[B].emplace_back(A, C);
    }

    start = 0;

    dijkstra();

    /* **
    ll goal = N-1;
    vector<ll> route = check_route(goal); //startからgoalまでの順番
    ll P = route.size(); //最小経路上のノードの個数
    printf("%lld %lld/%lld\n", d[goal], P, N);
    */

    return 0;
}