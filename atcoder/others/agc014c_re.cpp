/*
<point>
・ひとステップ前で、Kブロック壊しておけば、
　現在のステップでは、自由にK歩だけ移動できる。
・１ステップ目で行けるマスだけを、初期位置の候補として、先にBFS用キューに入れておく。
・最終的な答えは、２ステップ目移行に歩いた歩数を、Kで割って（繰り上げ）、
　１ステップ目の文、＋１したものになる。
<caution>
・初期位置の候補を、キューに入れるとき、「K歩以内」の条件を忘れていた。
・２回めのBFSに於いて、ゴール判定を、遷移先のところでやってしまうと、
　最初からゴールしている場合を取りこぼしてしまう。
*/

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
#define F first
#define S second

using namespace std;

const int INF = 1e9;
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};

int H,W,K;
string A[810];

int main() {
  cin>>H>>W>>K;
  int startX, startY;
  REP(i,0,H){
    cin>>A[i];
    REP(j,0,W){
      if(A[i][j]=='S'){
        startY = i;
        startX = j;
      }
    }
  }

  int d[810][810], td[810][810];
  REP(i,0,H)REP(j,0,W) d[i][j] = INF, td[i][j] = INF;
  queue< pair<int,int> > tq;
  queue< pair<int,int> > q;
  tq.push(make_pair(startY,startX));
  q.push(make_pair(startY,startX));
  d[startY][startX] = 0;
  td[startY][startX] = 0;

  while(!tq.empty()){
    pair<int,int> nowPos = tq.front();
    tq.pop();
    if(td[nowPos.F][nowPos.S] == K) continue;
    REP(k,0,4){
      int nextY = nowPos.F + dy[k], nextX = nowPos.S + dx[k];
      if(!CH(nextY,0,H) || !CH(nextX,0,W)) continue;
      if(A[nextY][nextX] == '#' || td[nextY][nextX] != INF) continue;
      td[nextY][nextX] = td[nowPos.F][nowPos.S] + 1;
      d[nextY][nextX] = 0;
      tq.push(make_pair(nextY,nextX));
      q.push(make_pair(nextY,nextX));
    }
  }

  int ans = INF;
  while(!q.empty()){
    pair<int,int> nowPos = q.front();
    q.pop();

    if(nowPos.F==0||nowPos.F==H-1||nowPos.S==0||nowPos.S==W-1){
      cout<<(d[nowPos.F][nowPos.S]+(K-1))/K + 1<<endl;
      return 0;
    }

    REP(k,0,4){
      int nextY = nowPos.F + dy[k], nextX = nowPos.S + dx[k];
      if(!CH(nextY,0,H) || !CH(nextX,0,W)) continue;
      if(d[nextY][nextX] != INF) continue;
      d[nextY][nextX] = d[nowPos.F][nowPos.S]+1;
      q.push(make_pair(nextY,nextX));
    }
  }

  return 0;
}
