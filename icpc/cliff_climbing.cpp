/*
2017_04_29_AC
<point>
・各マスについて、右足と左足それぞれ状態を区別して、
　W*H＊２個の状態数でダイクストラをする。
・初期位置は、すべてのSマスに対して、右足と左足を試して、
　結果が最も小さいものを最後に選ぶ。
<caution>
・配列のイデックス指定で、iとjが逆になっていた。
・構造体の書き方を確認して多く必要がある。（順序のルールも含めて）
<Question>
・現状態が右足か左足かによって、次のマスのX座標の決め方を分岐している部分を、
　もっとスマートに書く方法を検討したい。
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
#define Y first
#define X second

using namespace std;

const int INF = 1000000000;

int W,H;
char s[65][35];
int d[65][35][2];

struct cliffState{
  int step;
  int y;
  int x;
  int side;
  cliffState(int _step, int _y, int _x, int _side){
    step = _step;
    y = _y;
    x = _x;
    side = _side;
  }
  bool operator >(const cliffState &e) const{
    return step > e.step;
  }
};

int main() {
  while(1){
    cin>>W>>H;
    if(W==0 || H==0) break;
    vector< pair<int, int> > iniv;
    REP(i,0,H){
      REP(j,0,W){
        cin>>s[i][j];
        if(s[i][j]=='S') iniv.push_back(make_pair(i,j));
      }
    }

    int ans = INF;

    /*初期位置の数だけ繰り返す（最大W＊H＊２回）*/
    REP(inipos,0,iniv.size()){
      REP(iniside,0,2){

        /*初期化*/
        REP(i,0,H)REP(j,0,W)REP(k,0,2) d[i][j][k] = INF;
        d[iniv[inipos].Y][iniv[inipos].X][iniside] = 0;

        priority_queue< cliffState, vector<cliffState>, greater<cliffState> > PQ;
        cliffState cs = cliffState(0,iniv[inipos].Y,iniv[inipos].X,iniside);
        PQ.push(cs);

        /*Dijkstra*/
        while(!PQ.empty()){

          cliffState nowPos = PQ.top();
          PQ.pop();
          if(d[nowPos.y][nowPos.x][nowPos.side] < nowPos.step) continue;

          REP(i,nowPos.y-2,nowPos.y+2+1){
            if(i < 0 || H <= i) continue;
            int diff;
            if(i == nowPos.y-2 || i == nowPos.y+2) diff = 1;
            else if(i == nowPos.y-1 || i == nowPos.y+1) diff = 2;
            else diff = 3;

            /*現在の足が左の場合*/
            if(nowPos.side == 0){
              REP(j,nowPos.x+1,nowPos.x+diff+1){
                if(j < 0 || W <= j || i < 0 || H <= i) continue;
                if(s[i][j] != 'X' && d[i][j][(nowPos.side+1)%2] == INF){
                  int nstep;
                  if(s[i][j] != 'S' && s[i][j] != 'T') nstep = nowPos.step + (int)(s[i][j]-'0');
                  else nstep = nowPos.step;
                  if(nstep < d[i][j][(nowPos.side+1)%2]){
                    d[i][j][(nowPos.side+1)%2] = nstep;
                    cliffState ncs = cliffState(nstep,i,j,(nowPos.side+1)%2);
                    PQ.push(ncs);
                  }
                }
              }
            /*現在の足が右の場合*/
            }else{
              REP(j,nowPos.x-diff,nowPos.x){
                if(j < 0 || W <= j) continue;
                if(s[i][j] != 'X' && d[i][j][(nowPos.side+1)%2] == INF){
                  int nstep;
                  if(s[i][j] != 'S' && s[i][j] != 'T') nstep = nowPos.step + (int)(s[i][j]-'0');
                  else nstep = nowPos.step;
                  if(nstep < d[i][j][(nowPos.side+1)%2]){
                    d[i][j][(nowPos.side+1)%2] = nstep;
                    cliffState ncs = cliffState(nstep,i,j,(nowPos.side+1)%2);
                    PQ.push(ncs);
                  }
                }
              }
            }

          }

        }

        int tans = INF;
        REP(i,0,H){
          REP(j,0,W){
            if(s[i][j] == 'T') tans = min(tans, min(d[i][j][0],d[i][j][1]));
          }
        }
        ans = min(ans,tans);

      }
    }

    if(ans == INF) cout<<-1<<endl;
    else cout<<ans<<endl;

  }
  return 0;
}
