/**
 * 深さ優先探索(DFS)
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
#include <stack>
#include <vector>
#include <pair>

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define CK(N, A, B) (A <= N && N < B)

using namespace std;

/*==================================================*/

const int NODE_SIZE = 10101;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int dx8[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy8[8] = { -1,-1,0,1,1,1,0,-1 };

int N;   //ノード数
int M;  // エッジ数
int R;  //制限ステップ
int start;  //開始ノード番号
int goal;  //目的ノード番号

vector<pair<int,int>> edge[NODE_SIZE];    //ノードの接続関係 <エッジの重み, 接続先ノード>
int graph[NODE_SIZE][NODE_SIZE];   //ノードの接続関係 (接続:整数, 他:-1)
bool visited[NODE_SIZE];  //ノードに訪れたことがあるか

int H;  //フィールドの高さ
int W;  //フィールドの幅
int start_y, start_x;    //開始座標

int field[NODE_SIZE][NODE_SIZE];    //格子状のフィールド (配列)
string field_s[NODE_SIZE];      //格子状のフィールド (string)
bool visited_f[NODE_SIZE][NODE_SIZE];  //座標に訪れたことがあるか

int dp[101010];
int dp_f[10101][10101];


/*==================================================*/

/* グラフ */

//深さ優先探索 (グラフ: vector, 再帰)
void dfs_vec(int curNode, int cost){  
  if(visited[curNode]) return;
  visited[curNode] = true;
  
  for(int i=0; i<edge[curNode].size(); i++){
    int nextNode = edge[curNode][i].second;
    int addCost = edge[curNode][i].first;
    if(!visited[nextNode]){
      dfs_vec(nextNode, cost + addCost);
    }
  }
}

//深さ優先探索 (グラフ: 配列, 再帰)
void dfs_arr(int curNode, int cost){
  if(visited[curNode]) return;
  visited[curNode] = true;
  
  for(int i=0; i<N; i++){
    if(graph[curNode][i] == -1) continue;
    int nextNode = i;
    int addCost = graph[curNode][i];
    if(!visited[nextNode]){
      dfs_arr(nextNode, cost + addCost);
    }
  }
}

//メモ化深さ優先探索 (グラフ: vector, 再帰, メモ化)
void dfs_vec_memo(int curNode, int cost){
  if(dp[curNode] <= cost) return;
  dp[curNode] = cost;

  if(curNode == goal) return;
  
  for(int i=0; i<edge[curNode].size(); i++){
    int nextNode = edge[curNode][i].second;
    int addCost = edge[curNode][i].first;
    dfs_vec_memo(nextNode, cost + addCost);
  }
}

//メモ化深さ優先探索 (グラフ: 配列, 再帰, メモ化)
void dfs_arr_memo(int curNode, int cost){
  if(dp[curNode] <= cost) return;
  dp[curNode] = cost;

  if(curNode == goal) return;
  
  for(int i=0; i<N; i++){
    if(graph[curNode][i] == -1) continue;
    int nextNode = i;
    int addCost = graph[curNode][i];
    dfs_arr_memo(nextNode, cost + addCost);
  }
}


/* 格子状のフィールド */

//深さ優先探索 (フィールド: 配列/string, 再帰)
void dfs_field(int cur_y, int cur_x, int cost) {
  if(visited_f[cur_y][cur_x]) return;
  visited_f[cur_y][cur_x] = true;

  for(int k=0; k<4; k++){
    int next_y = cur_y + dy[k];
    int next_x = cur_x + dx[k];
    if(!CK(next_y,0,H) || !CK(next_x,0,W)) continue;  //範囲外
    if(!visited_f[next_y][next_x]){
      dfs_field(next_y, next_x, cost + 1);
    }
  }
}

//深さ優先探索 (フィールド: 配列/string, 再帰, メモ)
void dfs_field_memo(int cur_y, int cur_x, int cost) {
  if(dp_f[cur_y][cur_x] <= cost) return;
  dp_f[cur_y][cur_x] = cost;

  for(int k=0; k<4; k++){
    int next_y = cur_y + dy[k];
    int next_x = cur_x + dx[k];
    if(!CK(next_y,0,H) || !CK(next_x,0,W)) continue;  //範囲外
    dfs_field(next_y, next_x, cost + 1);
  }
}


/* スタック実装 (スタックオーバーフロー対策)*/

//深さ優先探索 (グラフ: vector, スタック)
void dfs_stack(int startNode) {
  stack<int, int> stk;  //<コスト, ノード>
  stk.push({0, startNode});

  while(!stk.empty()){
    int curNode = stk.top().second;
    int cost = stk.top().first;
    st.pop();

    visited[curNode] = true;

    for(int i=0; i<edge[curNode].size(); i++){
      int nextNode = edge[curNode][i].second;
      int addCost = edge[curNode][i].first;
      if(!visited[nextNode]){
        stk.push({cost + addConst, nextNode});
      }
    }
  }
}


/*==================================================*/
/* example */

int main(){

  //深さ優先探索 (グラフ: vector, 再帰)
  /* ここでグラフ作成 */
  dfs_vec(start, 0);

  //深さ優先探索 (グラフ: 配列, 再帰)
  REP(i,0,N)REP(j,0,N) graph[i][j] = -1;
  /* ここでグラフ作成 */
  dfs_arr(start, 0);

  //メモ化深さ優先探索 (グラフ: vector, 再帰, メモ化)
  /* ここでグラフ作成 */
  REP(i,0,N) dp[i] = INF;
  dfs_vec_memo(start, 0);

  //メモ化深さ優先探索 (グラフ: 配列, 再帰, メモ化)
  REP(i,0,N)REP(j,0,N) graph[i][j] = -1;
  /* ここでグラフ作成 */
  REP(i,0,N) dp[i] = INF;
  dfs_arr_memo(start, 0);

  //深さ優先探索 (フィールド: 配列/string, 再帰)
  /* ここでグラフ作成 */
  dfs_vec_memo(start, 0);

  //深さ優先探索 (グラフ: vector, スタック)
  /* ここでグラフ作成 */
  dfs_stack(start);

  return 0;
}