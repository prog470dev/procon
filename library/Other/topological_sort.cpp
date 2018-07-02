/*
 * トポロジカルソート O(|V| + |E|)
 * 全ての辺が同じ向きにそろう
 * プロジェクトのアローダイアグラムと同じ
 * クリティカルパスなども求められる
 * 深さ優先でやる方法と幅優先でやる方法がある(実装は幅優先)
 *  MEMO
 *   - DAGなら必ずトポロジカルソートが存在する
 *   - tsort関数はDAGじゃなければからのベクターを返すのでDAG判定も可能
 *
 *
 */


#include "bits/stdc++.h"
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

const ll NODE_SIZE = 101010;
ll N; //ノード数
ll M; //エッジ数
vector<vector<pair<ll, ll>>> edge(NODE_SIZE);   //<ノード, コスト> , 普通の有向辺
vector<vector<pair<ll, ll>>> edge2(NODE_SIZE);   //<ノード, コスト> , 逆向きの有向辺

vector<ll> tsort(vector<vector<pair<ll, ll>>> g) {
    ll k = 0;
    vector<ll> in(N,0);
    vector<ll> ord(N);
    // 自分に繋がっているエッジの次数カウント
    for (auto es : g)
        for (auto e : es) in[e.first]++;
    queue<ll> q;
    for (ll i = 0; i < N; ++i)
        if (in[i] == 0) q.push(i);
    while (!q.empty()) {
        ll node = q.front();
        q.pop();
        ord[k++] = node;
        for (auto e : g[node])
            if (--in[e.first] == 0){
                q.push(e.first); //使ってもいいノードの追加
            }

    }
    return *max_element(in.begin(), in.end()) == 0 ? ord : vector<ll>();
}

int main(){
    cin>>N>>M;
    ll A,B,C;
    REP(i,0,M){
        cin>>A>>B>>C;
        edge[A].emplace_back(B,C);
        edge2[B].emplace_back(A,C);
    }
    vector<ll> route = tsort(edge);//トポロジカルソートの作成

    vector<ll> D(N, -inf); // トポロジカルグラフのスタートからの距離
    D[route[0]] = 0;
    //最早
    for(auto v: route) {
        for(auto uc: edge[v]) {
            ll node = uc.first;
            ll c = uc.second;
            D[node] = max(D[node], D[v] + c); //一番時間がかかる有向辺
        }
    }
    ll T = D[route[N-1]];
    vector<bool> used(N,0);
    used[route[N-1]] = 1;

    //最遅
    reverse(route.begin(), route.end());
    for(auto v: route) {
        if (!used[v]) continue;
        for(auto uc: edge2[v]) {
            ll node = uc.first;
            ll cost = uc.second;
            if (D[node] + cost == D[v]) {//最早と最遅の距離が一致してるとこのがクリティカルパスのノード
                used[node] = 1;
            }
        }
    }
    // クリティカルパス
    vector<ll> critical_path;
    for(auto v:route){
        if(used[v]) critical_path.push_back(v);
    }

    return 0;
}