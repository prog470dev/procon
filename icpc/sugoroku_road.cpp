#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

const int INF = 1000000005;
int N, p[100005], dp[100005];
/*
void dfs(int prevPos, int currentPos, int step){
  if(dp[currentPos] <= step) return;
  dp[currentPos] = step;
  if(currentPos == N-1) return;
  if(p[currentPos] > 0) dfs(currentPos, min(N - 1, currentPos + p[currentPos]), step);
  else if(p[currentPos] < 0) dfs(currentPos, max(0, currentPos + p[currentPos]), step);
  else{
    REP(i,1,7){
      dfs(currentPos, min(N-1, currentPos+i), step+1);
    }
  }
  return;
}
*/
int main() {
  cin>>N;
  REP(i,0,N) cin>>p[i];
  REP(i,0,N) dp[i] = INF;
  dp[0] = 0;

  /*DFS*/
  //dfs(-1,0,0);

  /*BFS*/
  queue< pair<int,int> > q;
  q.push(make_pair(0,0));
  while(!q.empty()){
    int currentPos = q.front().first;
    int currentStep = q.front().second;
    q.pop();
    REP(i,1,7){
        int nextPos = currentPos + i;
        if(p[nextPos] != 0){
          int tPos = nextPos;
          bool flag = true;
          while(p[tPos] != 0){
            if(dp[tPos] > currentStep+1){
              dp[tPos] = currentStep+1;
              //イベントマスは、重複して訪問しないように、DP配列は更新しておくが、
              //このマスでサイコロは振れないので、キューにはpushしない。
            }else{
              flag = false;
              break;
            }
            tPos += p[tPos];
          }
          if(flag && dp[tPos] > currentStep+1) dp[tPos] = currentStep+1,q.push(make_pair(tPos, currentStep+1));
        }else{
          if(dp[nextPos] > currentStep+1) dp[nextPos] = currentStep+1, q.push(make_pair(nextPos, currentStep+1));
        }
    }
    if(dp[N-1] < INF) break;
  }

  cout<<dp[N-1]<<endl;

  return 0;
}
