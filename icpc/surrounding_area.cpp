/*
2017_02_24_AC
（疑問）
・最後の塗り方は、なぜこの方法でうまくいくのか？
（トラブル）
・dfs()ないの再帰するfor文で、条件漏れにより範囲外でも呼び出していた。
・memesetは、<cstring>がないとコンパイルエラー
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int w, h;
int grand[55][55];
string s[55];
bool flag[55][55];

void dfs(int y, int x){
  if(s[y][x] != '.' || !flag[y][x]) return;
  flag[y][x] = false;
  for(int k=0; k<4; k++){
    if(!CH(x + dx[k],0,w) || !CH(y + dy[k],0,h)) continue;
    if(s[y + dy[k]][x + dx[k]] != '.') continue;
    if(grand[y + dy[k]][x + dx[k]] != 3) grand[y + dy[k]][x + dx[k]] = grand[y][x];
  }
  for(int k=0; k<4; k++){
    if(!CH(x + dx[k],0,w) || !CH(y + dy[k],0,h)) continue;
    if(s[y + dy[k]][x + dx[k]] != '.') continue;
    dfs(y + dy[k], x + dx[k]);
  }
}

int main() {

  while(1){
    cin>>w>>h;
    if(w==0 && h==0) break;
    for(int i=0; i<h; i++){
      cin>>s[i];
    }
    memset(grand, 0, sizeof(grand));

    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        if(s[i][j] == '.'){
          for(int k = 0; k<4; k++){
            if(!CH(j + dx[k],0,w) || !CH(i + dy[k],0,h)) continue;
            int posx = j + dx[k], posy = i + dy[k];
            while(1){
              if(!CH(posx,0,w) || !CH(posy,0,h)){
                break;
              }else if(s[posy][posx] == 'W'){
                int tx = posx - dx[k], ty = posy - dy[k];
                while(1){
                  if(grand[ty][tx] == 0 || grand[ty][tx] == 1) grand[ty][tx] = 1;
                  else grand[ty][tx] = 3;
                  if(tx == j && ty == i ) break;
                  tx -= dx[k];
                  ty -= dy[k];
                }
                break;
              }else if(s[posy][posx] == 'B'){
                int tx = posx - dx[k], ty = posy - dy[k];
                while(1){
                  if(grand[ty][tx] == 0 || grand[ty][tx] == 2) grand[ty][tx] = 2;
                  else grand[ty][tx] = 3;
                  if(tx == j && ty == i ) break;
                  tx -= dx[k];
                  ty -= dy[k];
                }
                break;
              }
              posx += dx[k];
              posy += dy[k];
            }
          }
        }
      }
    }

    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        memset(flag, true, sizeof(flag));
        dfs(i, j);
      }
    }

    int wcnt=0, bcnt=0;
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        if(grand[i][j] == 1) wcnt++;
        if(grand[i][j] == 2) bcnt++;
      }
    }
    cout<<bcnt<<" "<<wcnt<<endl;

  }
  return 0;
}
