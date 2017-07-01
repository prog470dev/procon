/*
深さ優先探索

概要：

使い方：

*/
//スタック実装
vector<int> v
stack<int> st;
st.push();

while(!st.empty()){
  int curNode = st.top();
  st.pop();
  REP(i,0,v.size()){
    if(/*条件を満たす*/){
      q.push(i);
    }
  }
}
//再帰関数実装
void dfs(int curNode){
  if(/*終了条件*/){
    return;
  }
  REP(i,0,v.size()){
    if(/*条件を満たす*/){
      dfs(v[i]);
    }
  }
  return;
}
//メモ化再帰
int dp[10010];
REP(i,0,10010) dp[i] = INF;

void dfs(int curNode){
  if(/*終了条件*/){
    return;
  }
  if(dp[i]){

  }
  REP(i,0,v.size()){
    if(/*条件を満たす*/){
      dfs(v[i]);
    }
  }
  return;
}


/*
幅優先探索
概要：

使い方：

*/
queue<int> q;
q.push();

while(q.empty()){
  int curNode = q.front();
  q.push();
  REP(i,0,v.size()){
    if(/*条件を満たす*/){
      q.push(/**/);
    }
  }
}
