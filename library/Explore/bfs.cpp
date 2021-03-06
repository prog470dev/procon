/**
 * 幅優先探索(BFS)
 *  - 時間計算量
 *      - O( |E| ) ※E:エッジの数
 *  - 探索対象
 *      - グラフ (配列/vector)
 *      - 格子状フィールド (配列/string)
 *  - MEMO
 *      - 格子状フィールドのマス移動コストは 1 としている.
 *      - 最大ステップ数(コスト) R を設定している.
*/

#include <iostream>
#include <queue>
#include <vector>

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define CK(N, A, B) (A <= N && N < B)

using namespace std;

/*==================================================*/

const int NODE_SIZE = 10101;

int N;   //ノード数
int M;  // エッジ数
int R;  //制限ステップ
int start;  //開始ノード番号

vector<pair<int,int>> edge[NODE_SIZE];    //ノードの接続関係 <エッジの重み, 接続先ノード>
int graph[NODE_SIZE][NODE_SIZE];   //ノードの接続関係 (接続:整数, 他:-1)

int dist[NODE_SIZE];
//幅優先探索 (グラフ: vector)
void bfs_vec(){
    queue<int> q; //<コスト, ノード>
    bool visited[NODE_SIZE];
    for(int i=0; i<N; i++) visited[i]=false;    //初期位置を設定
    for(int i=0; i<N; i++) dist[i] = -1;// 最後まで-1なら到達不可能
    q.push(start);  //開始ノードを追加
    dist[start] = 0; // 初期状態のコスト
    while(!q.empty()){
        int curNode = q.front();
        int curStep = dist[curNode];
        q.pop();
        if(curStep > R) continue;    //制限ステップ数を超えたら打ち切り
        if(visited[curNode]) continue;
        visited[curNode] = true;

        for(auto nextEdge: edge[curNode]){
            int nextNode = nextEdge.second;
            int cost = nextEdge.first;
            if(!visited[nextNode]){     //未到達のノードだけpush.
                q.push(nextNode);
                dist[nextNode] = curStep + cost;
            }
        }
    }
}


//幅優先探索 (グラフ: 配列)
void bfs_arr(){
    queue<int> q; //<コスト, ノード>
    bool visited[NODE_SIZE];
    for(int i=0; i<N; i++) visited[i]=false;    //初期位置を設定
    for(int i=0; i<N; i++) dist[i] = -1;// 最後まで-1なら到達不可能
    q.push(start);  //開始ノードを追加
    dist[start] = 0; // 初期状態のコスト

    while(!q.empty()){
        int curNode = q.front();
        int curStep = dist[curNode];
        q.pop();
        if(curStep > R) continue;    //制限ステップ数を超えたら打ち切り
        if(visited[curNode]) continue;
        visited[curNode] = true;

        for(int nextNode=0; nextNode<N; nextNode++){
            if(graph[curNode][nextNode] != -1) continue;
            if(!visited[nextNode]){     //未到達のノードだけpush.
                q.push(nextNode);
                dist[nextNode] = curStep + graph[curNode][nextNode];
            }
        }
    }
}


int H;  //フィールドの高さ
int W;  //フィールドの幅
int start_y, start_x;    //開始座標

int field[NODE_SIZE][NODE_SIZE];    //格子状のフィールド (配列)
string field_s[NODE_SIZE];      //格子状のフィールド (string)

int d[NODE_SIZE][NODE_SIZE];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int dx8[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy8[8] = { -1,-1,0,1,1,1,0,-1 };

//幅優先探索 (フィールド: 配列/string)
void bfs_field() {
    queue<pair<int,int>> q; //<コスト, 座標(y,x)>
    bool visited[H][W];
    REP(i,0,H)REP(j,0,W) visited[i][j]=false; // 初期位置を設定
    REP(i,0,H)REP(j,0,W) d[i][j] = -1;// 最後まで-1なら到達不可能
    q.push({start_y, start_x});  // 開始ノードを追加
    d[start_y][start_x] = 0; // 初期状態のコスト
    while(!q.empty()){
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        int curStep = d[cur_y][cur_x];
        q.pop();
        if(curStep > R) continue;    //制限ステップ数を超えたら打ち切り
        if(visited[cur_y][cur_x]) continue;
        visited[cur_y][cur_x] = true;

        REP(k,0,4){
            //REP(k,0,8){
            int next_y = cur_y + dy[k];
            int next_x = cur_x + dx[k];
            //int next_y = cur_y + dy8[k];
            //int next_x = cur_y + dx8[k];

            if(!CK(next_y,0,H) || !CK(next_x,0,W)) continue;  //範囲外
            /* ここに問題ごとの条件 */
            if(!visited[next_y][next_x]){     //未到達の座標だけpush.
                q.push({next_y, next_x});
                d[next_y][next_x] = d[cur_y][cur_x] + 1;
            }
        }
    }
}

/*==================================================*/
/* example */

int main(){

    //幅優先探索 (グラフ: vector)
    /* ここでグラフ作成 */
    bfs_vec();


    //幅優先探索 (グラフ: 配列)
    REP(i,0,N)REP(j,0,N) graph[i][j] = -1;  //初期化(-1 => 接続無し)
    /* ここでグラフ作成 */
    bfs_arr();


    //幅優先探索 (フィールド: 配列/string)
    /* ここでグラフ作成 */
    bfs_field();

    return 0;
}
