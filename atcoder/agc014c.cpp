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

  bool visit[810][810];
  REP(i,0,H)REP(j,0,W) visit[i][j] = false;
  visit[startY][startX] = true;
  //test
  int steps[805][805];
  REP(i,0,H)REP(j,0,W) steps[i][j] = -1;
  steps[startY][startX] = 0;

  queue< pair< pair<int,int>, pair<int,pair<int,int> > > > q;
  pair< pair<int,int>, pair<int,pair<int,int> > > tmp = make_pair(make_pair(startY,startX),make_pair(1,make_pair(0,0)));
  q.push(tmp);
  visit[startY][startX] = true;

  while(!q.empty()){

    pair<int,int> nowPos = q.front().F; //現在の座標
    int nowStep = q.front().S.F;  //現在のステップ数
    pair<int,int> nowState = q.front().S.S; //現在の歩数、（前ステップで）壊したブロック数
    q.pop();

    REP(k,0,4){

      int nextY = nowPos.F + dy[k], nextX = nowPos.S + dx[k];

      if(!CH(nextY,0,H) || !CH(nextX,0,W)) continue;
      //if(visit[nextY][nextX]) continue;
      if(steps[nextY][nextX] != -1 && steps[nextY][nextX] <= nowStep) continue;

      if(A[nextY][nextX] == '#'){
        if(nowStep==1){  //これでいいのか？
          tmp = make_pair(make_pair(nextY,nextX),make_pair(nowStep+1,make_pair(1,1)));
          //test
          steps[nextY][nextX] = nowStep+1;
        }else{
          if(nowState.S < K){
            tmp = make_pair(make_pair(nextY,nextX),make_pair(nowStep,make_pair(nowState.F,nowState.S+1)));
            //test
            steps[nextY][nextX] = nowStep;
          }else{
            tmp = make_pair(make_pair(nextY,nextX),make_pair(nowStep+1,make_pair(0,1)));//??
            //test
            steps[nextY][nextX] = nowStep+1;
          }
        }
      }
      if(A[nextY][nextX] == '.'){
        if(nowState.F < K){
          tmp = make_pair(make_pair(nextY,nextX),make_pair(nowStep,make_pair(nowState.F+1,nowState.S)));
          //test
          steps[nextY][nextX] = nowStep;
        }else{
          tmp = make_pair(make_pair(nextY,nextX),make_pair(nowStep+1,make_pair(1,0)));//ブロック数はどうなる？
          //test
          steps[nextY][nextX] = nowStep+1;
        }
      }
      visit[nextY][nextX] = true;
      q.push(tmp);
    }
  }

  int ans = 1e9;
  REP(i,0,H)REP(j,0,W) if(i==0||i==H-1||j==0||j==W-1) ans = min(ans, steps[i][j]);
  cout<<ans<<endl;

  return 0;
}
