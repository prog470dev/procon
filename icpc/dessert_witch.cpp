#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
string s[8];

bool dfsa(){
  int cnt=0, linecnt[8]={}, tx = -1, ty = -1;
  REP(i,0,8){
    REP(j,0,8){
      if(s[i][j] != '.') continue;
      int line[8] = {};
      REP(k,0,8){
        if(!CH(j + dx[k], 0, 8) || !CH(i + dy[k], 0, 8)) continue;
        //if(s[i + dy[k]][j + dx[k]] != 'x') continue;
        int posx = j + dx[k], posy = i + dy[k];
        int tmpline = 1;
        bool flag = false;
        while(s[posy][posx] == 'x'){
          if(!CH(posx + dx[k], 0, 8) || !CH(posy + dy[k], 0, 8)) break;
          if(s[posy + dy[k]][posx + dx[k]] == 'o'){
            flag = true;
            break;
          }
          tmpline++;
          posx += dx[k];
          posy += dy[k];
        }
        if(flag){
          line[k] = tmpline;
        }
      }
      int tmpcnt = 0;
      REP(k,0,8) tmpcnt += line[k];
      if(cnt < tmpcnt){
        cnt = tmpcnt;
        REP(k,0,8) linecnt[k] = line[k];
        tx = j; ty = i;
      }
    }
  }
  if(cnt != 0){
    s[ty][tx] = 'o';
    REP(k,0,8){
      int posx = tx, posy = ty;
      REP(i,0,linecnt[k]){
        posx += dx[k];
        posy += dy[k];
        s[posy][posx] = 'o';
      }
    }
  }
  return (cnt != 0) ? true : false;
}

bool dfsb(){
  int cnt=0, linecnt[8]={}, tx = -1, ty = -1;
  RREP(i,0,8){
    RREP(j,0,8){
      if(s[i][j] != '.') continue;
      int line[8] = {};
      REP(k,0,8){
        if(!CH(j + dx[k], 0, 8) || !CH(i + dy[k], 0, 8)) continue;
        //if(s[i + dy[k]][j + dx[k]] != 'o') continue;
        int posx = j + dx[k], posy = i + dy[k];
        int tmpline = 1;
        bool flag = false;
        while(s[posy][posx] == 'o'){
          if(!CH(posx + dx[k], 0, 8) || !CH(posy + dy[k], 0, 8)) break;
          if(s[posy + dy[k]][posx + dx[k]] == 'x'){
            flag = true;
            break;
          }
          tmpline++;
          posx += dx[k];
          posy += dy[k];
        }
        if(flag){
          line[k] = tmpline;
        }
      }
      int tmpcnt = 0;
      REP(k,0,8) tmpcnt += line[k];
      if(cnt < tmpcnt){
        cnt = tmpcnt;
        REP(k,0,8) linecnt[k] = line[k];
        tx = j; ty = i;
      }
    }
  }
  if(cnt != 0){
    s[ty][tx] = 'x';
    REP(k,0,8){
      int posx = tx, posy = ty;
      REP(i,0,linecnt[k]){
        posx += dx[k];
        posy += dy[k];
        s[posy][posx] = 'x';
      }
    }
  }
  return (cnt != 0) ? true : false;
}



int main() {

  for(int i=0; i<8; i++){
    cin>>s[i];
  }

  int turn = 0;
  bool bflag = true;

  while(1){
    bool nflag;
    if(turn % 2 == 0){
      nflag = dfsa();
    }else{
      nflag = dfsb();

    }
    if(!bflag && !nflag) break;
    bflag = nflag;
    turn++;
  }

  for(int i=0; i<8; i++){
    cout<<s[i]<<endl;
  }

  return 0;
}
