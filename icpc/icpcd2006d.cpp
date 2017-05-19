/*
・上限１０回だから、全探索するだけでいい。
・探索中に状態を戻す際、壊したブロックをどう戻すかがポイント。
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int w, h;
int grid[25][25];
int sx, sy, gx, gy;
int ans;

int dfs(int posx, int posy, int cnt){
  //test
  //cout<<"[ "<<posx<<" , "<<posy<<" ]"<<" cnt: "<<cnt<<endl;
  for(int i=0; i<4; i++){
    if(grid[posy+dy[i]][posx+dx[i]] == 1){
      continue;
  }
    if(posy+dy[i] == -1 || posy+dy[i] == h || posx+dx[i] == w || posx+dx[i] == -1 ){
      continue;
    }

    //ここで覚えておく
    int nx = posx;
    int ny = posy;

    while(1){
      nx += dx[i];
      ny += dy[i];
      if(nx < 0 || w <=  nx || ny < 0 || h <= ny){
        break;
      }
      else if(grid[ny][nx] == 3){
        return cnt + 1;
      }
      else if(grid[ny][nx] == 1 && cnt < 10){
        grid[ny][nx] = 0;
        int dfscnt = dfs(nx - dx[i], ny - dy[i], cnt+1);
        grid[ny][nx] = 1;
        ans = min(ans, dfscnt);
        break;
      }
    }
  }

  return ans;

}

int main() {
  while(true){

    cin>>w>>h;
    if(w==0 &&  h==0) break;

    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        cin>>grid[i][j];
        if(grid[i][j] == 2) sx = j, sy = i;
        if(grid[i][j] == 3) gx = j, gy = i;
      }
    }

    int posx = sx, posy = sy;
    ans = 11;

    int tmp = dfs(posx, posy, 0);

    if(tmp > 10) cout<<-1<<endl;
    else cout<<tmp<<endl;

  }


  return 0;
}
