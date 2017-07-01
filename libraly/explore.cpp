/*
付録：
  方向差分
*/
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };


/*
深さ優先探索
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
幅優先探索
*/
queue<int> q;
q.push(/**/);

while(q.empty()){
  int curNode = q.front();
  q.pop();
  if(/*ゴールに到達*/) break;
  REP(nextNode, 0, v[curNode].size()){
    if(/*条件を満たす*/){
      q.push(/**/);
    }
  }
}
