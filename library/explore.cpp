/*
付録：
  方向差分
*/
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };


/*
DFS（深さ優先探索）

計算量 :
   O( || )

*/

//スタック実装
stack<int> st;
st.push(/**/);

while(!st.empty()){
  int curNode = st.top();
  st.pop();
  REP(nextNode,0,v[curNode].size()){
    if(/*条件を満たす*/){
      q.push(nextNode);
    }
  }
}

//再帰関数実装
int dfs(int curNode, int step){
  if(/*終了条件*/){
    return step;
  }
  REP(nextNode, 0, v[curNode].size()){
    if(/*条件を満たす*/){
      dfs(v[i],step+1);
    }
  }
  return /*ループ中の計算結果*/;
}

//メモ化再帰
int dp[100010];
REP(i,0,100010) dp[i] = INF;

int dfs(int curNode, int step){
  if(/*終了条件*/){
    return step;
  }
  if(dp[curNode]!=INF){ /*すでに探索済み*/
    return dp[curNode];
  }
  REP(nextNode,0,v[curNode].size()){
    if(/*条件を満たす*/){
      dfs(nextNode, step+1);
    }
  }
  return dp[curNode] = /*ループ中の計算結果*/;
}



/*
 BFS（幅優先探索）

 概要（使用例）：
    グラフ v に対して、ノードiからのBFSを行う.
 　　ノードiから制限距離(R[i])以内で到達するノードまでの経路の辺に、
    重さ(C[i])を付け、新しいグラフ(edge[][])を作成する.

    int N;   //ノード数
    vector<int> v[5010];    //ノードの接続関係
    ※v[i][j]が存在 => ノードiとノードjは接続されている.

 計算量 :
    O( |E| ) ※E:エッジの数
 */

REP(i,0,N){
    queue<pair<int,int>> q; //<コスト, ノード>
    bool visited[5010];
    REP(i,0,N) visited[i]=false;    //初期位置を設定
    q.push({0,i});

    while(!q.empty()){
        int curNode = q.front().S;
        int curStep = q.front().F;
        q.pop();
        if(curStep > R[i]) continue;    //制限ステップ数を超えたら打ち切り
        visited[curNode] = true;
        if(i != curNode) edge[i].push_back({C[i],curNode});
        REP(j,0,v[curNode].size()){
            int nextNode = v[curNode][j];
            if(!visited[nextNode]){     //未到達のノードだけpush.(その他問題により条件を追加)
                q.push({curStep+1,nextNode});
            }
        }
    }
}
