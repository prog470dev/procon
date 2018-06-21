/**
 * ベルマン・フォード法
 *  - 概要
 *      - 開始ノードから任意のノードへの最短距離を計算
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

#define REP(i, a, b) for (int i = a; i < b; i++)

using namespace std;
typedef long long ll;

const ll INF = 1e18;

const ll NODE_SIZE = 1010;
ll N;  //グラフのノードの数
ll M;  //グラフの辺の数
vector< pair<ll, pair<ll, ll>> > edge;   //辺情報　<コスト, <formノード, toノード>>
ll d[NODE_SIZE];   //始点ノードからノードiへの最短距離(score)
ll start;  //開始ノード番号

bool negCloCir; //負の閉路があるかどうかのフラグ
bool negNode[NODE_SIZE];
/*==================================================*/

//ベルマン・フォード法
bool bellman_ford() {
    bool update;
    REP(i,0,N){
        update = false;
        for(auto e:edge){
            ll from = e.second.first;
            ll to = e.second.second;
            if(d[from] != INF && d[to] > d[from] + e.first){
                d[to] = d[from] + e.first;
                update = true;

            }
        }
        if(!update) break;
    }
    return update; //true: 負の閉路が存在
}

void check_negative() {
    REP(i,0,N+1){
        for(auto e:edge){
            ll from = e.second.first;
            ll to = e.second.second;
            if(d[from] != INF && d[to] > d[from] + e.first){
                d[to] = d[from] + e.first;
                negNode[from] = negNode[to] = true;
            }
        }
    }
}


/*==================================================*/
int main(){
    //ここでグラフの生成
    edge.clear();
    REP(i, 0, N) d[i] = INF;
    REP(i, 0, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edge.push_back({-c, {a, b}});
    }
    start = 0;
    d[start] = 0;
    negCloCir = bellman_ford();

    if (negCloCir) {
        //負の閉路がある場合の処理
        //例: 負の閉路によって更新されてしまうノードチェック(ABC061 D)
        REP(i,0,N) negNode[i]=false;
        check_negative();
        if(negNode[N-1]){
            p("inf");
        }else{
            p(-d[N - 1]);
        }
    } else {
        p(-d[N - 1]);
    }
    return 0;
}

