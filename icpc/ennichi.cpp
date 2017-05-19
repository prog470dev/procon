/*
2017_05_03_AC
・ブロックがないマスとの交換はあり？？
　（”状態を互いに入れ替える”だからOKっぽいけど・・・）
・stringの配列は、１要素ずつコピーしないとバグる。
・botomの更新のバグが有った。（縦手に２個以上まとまって浮いているときに発生）
・落下を最優先の処理にする。（ブロックなしマスを入れ替えた場合、消滅より落ちるのが先）
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

int dx[] = {1,-1};

int h,w,n;
string s[35], ts[35];
bool d[35][35];
set< pair<int,int> > st[35][35]; //st[i][j]: すでに[i][j]と入れ替えた座標

bool dfs(){
  while(1){
    //fall
    REP(i,0,w){
      int botom = -1;
      for(int j = h-1; 0<=j; j--){
        if(ts[j][i] == '.'){
          botom = j;
          break;
        }
      }
      for(int j=botom-1; 0<=j; j--){
        if(ts[j][i] != '.'){
          ts[botom][i] = ts[j][i];
          ts[j][i] = '.';
          botom--;
        }
      }
    }

    REP(i,0,h)REP(j,0,w) d[i][j] = false;
    //check row
    REP(i,0,h){
      int cnt = 1;
      char pre = ts[i][0];
      REP(j,1,w){
        if(pre == ts[i][j] && ts[i][j] != '.'){
          cnt++;
        }else{
          if(cnt >= n){
            for(int k=j-1; cnt!=0; k--) d[i][k] = true, cnt--;
            cnt = 1;
          }else{
            cnt = 1;
          }
        }
        pre = ts[i][j];
      }
      if(cnt >= n && ts[i][w-1] != '.'){
        for(int j=w-1; cnt!=0; j--) d[i][j] = true, cnt--;
      }
    }
    //check col
    REP(j,0,w){
      int cnt = 1;
      char pre = ts[0][j];
      REP(i,1,h){
        if(pre == ts[i][j] && ts[i][j] != '.'){
          cnt++;
        }else{
          if(cnt >= n){
            for(int k=i-1; cnt!=0; k--) d[k][j] = true, cnt--;
            cnt = 1;
          }else{
            cnt = 1;
          }
        }
        pre = ts[i][j];
      }
      if(cnt >= n && ts[h-1][j] != '.'){
        for(int i=h-1; cnt!=0; i--) d[i][j] = true, cnt--;
      }
    }

    //break blocks
    REP(i,0,h){
      REP(j,0,w){
        if(d[i][j] == true) ts[i][j] = '.';
      }
    }

    bool left = false;
    bool bre = false;
    REP(i,0,h)REP(j,0,w) {
      if(ts[i][j] != '.') left = true;
      if(d[i][j] == true) bre = true;
    }
    if(!bre) return false;
    if(!left) return true;

  }
}

int main(){
  cin>>h>>w>>n;
  REP(i,0,h) cin>>s[i];

  REP(i,0,h){
    REP(j,0,w){
      REP(k,0,2){
        if(j+dx[k] < 0 || w <= j+dx[k]) continue;
        if(st[i][j].find(make_pair(i, j+dx[k])) != st[i][j].end()
          || st[i][j+dx[k]].find(make_pair(i, j)) != st[i][j+dx[k]].end()) continue;
        st[i][j].insert(make_pair(i, j+dx[k]));
        st[i][j+dx[k]].insert(make_pair(i, j));
        st[i][j].insert(make_pair(i, j+dx[k]));
        char tmp = s[i][j+dx[k]];
        s[i][j+dx[k]] = s[i][j];
        s[i][j] = tmp;
        //copy
        REP(ii,0,h) ts[ii] = s[ii];
        bool ans = dfs();
        if(ans){
          cout<<"YES"<<endl;
          return 0;
        }
        s[i][j] = s[i][j+dx[k]];
        s[i][j+dx[k]] = tmp;
      }
    }
  }

  cout<<"NO"<<endl;

  return 0;
}
