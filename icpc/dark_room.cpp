/*
2017_04_23_AC
<point>
・開始時点で、すべての暗い部屋に人がいると考える。
・各暗い部屋に人がいるかいないかの状態は、１６ビットの整数で記憶できる。
・暗い部屋（最大１６個）の遷移だけ確認すればよい。
<caution>
・ビットの桁数は実際のD[i]の値でなく、iの方。
・次状態へのビット演算では、暗い部屋の番号は１ビットだけ立たせて、
　それ以外は０になっている配列を作っておくと良い。
　（そうしないと、毎回シーケンシャルに遷移先ノードが、
　　何番目の暗い部屋か探索しなくてはならない。）
・すでに経験したかどうかの配列も用意しておく。
<question>
・消すビットと、立てるビットのベクターを作っておき、最後に処理する方法と、
　次状態を０で初期化しておき、遷移先のビットを毎回立てる方法が、
　１００倍近く実行速度が違う原因が不明。
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

using namespace std;

int N,M,K,D[20],v[105][105];
bool visit[(1<<16)];
int bits[105] = {};

int main() {
  cin>>N>>M>>K;
  REP(i,0,M){
    int d;
    cin>>d;
    D[i] = d-1;
    bits[D[i]] = (1<<i);
  }
  REP(i,0,N){
    REP(j,0,K){
      cin>>v[i][j];
    }
  }
  REP(i,0,(1<<16)) visit[i] = false;
  queue< pair<int, int> > stq;  //暗い部屋の存在状態, カウント
  stq.push(make_pair((1<<M)-1, 0));
  visit[(1<<M)-1] = true;;
  while(!stq.empty()){
    int state = stq.front().first;
    int step = stq.front().second;
    stq.pop();

    REP(j,0,K){ /*状態stateから命令Kが実行されたときの変化の処理*/
      int nextState = 0;
      /*
      int nextState = state;
      vector<int> fromv;
      vector<int> tov;
      */
      REP(i,0,M){
        if(state & (1<<(i/*D[i]*/))){
          //fromv.push_back(/*i*//*D[i]*/bits[D[i]]);
          ////REP(k,0,M) if(v[D[i]][j]-1 == D[k]) tov.push_back(k);
          //if(bits[v[D[i]][j]-1] != 0) tov.push_back(bits[v[D[i]][j]-1]);
          if(bits[v[D[i]][j]-1] != 0) nextState |= bits[v[D[i]][j]-1];
        }
      }
      /*
      //REP(i,0,fromv.size()) nextState &= ~(1<<fromv[i]); //fromステージのビットを落とす
      REP(i,0,fromv.size()) nextState &= ~fromv[i];
      //REP(i,0,tov.size()) nextState |= (1<<tov[i]);  //toステージのビットを立てる
      REP(i,0,tov.size()) nextState |= tov[i];
      */
      if(nextState==0){
        cout<<step+1<<endl;
        return 0;
      }
      if(!visit[nextState]){
        stq.push(make_pair(nextState, step+1));
        visit[nextState] = true;
      }
    }
  }

  return 0;
}
