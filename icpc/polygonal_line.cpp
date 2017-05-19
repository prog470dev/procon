/*
2017_05_07
<point>
・入力された折れ線について、各頂点の情報を(辺の長さ,折れる方向)のpairで保持しておく。
<caution>
・折れ線の入力の始点は、どちらの端点から始まっているかわからないので、
　両方向から調べる。
<think>
・回転させるやり方もあるはず。（→どうやる？）
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
#define X first
#define Y second

using namespace std;

int n,m;

int main() {
  while(1){
    int ms[55];
    cin>>n;
    if(n==0) break;
    pair<int,int> lines[55][15];
    REP(i,0,n+1){
      cin>>m;
      ms[i] = m;
      REP(j,0,m){
        int x, y;
        cin>>x>>y;
        lines[i][j] = make_pair(x,y);
      }
    }
    //
    pair<int,int> data[55][15];//長さ、一つ前の点に対して曲がっている方向（左０，右１）※第一点,最終点は−１
    REP(i,0,n+1){
      int dir=-1, len=-1;
      REP(j,1,m-1){//j-1とjから、j+1の点を見て、jに値を入れる
        /*縦線*/
        if(lines[i][j-1].X == lines[i][j].X){
          if(lines[i][j-1].Y < lines[i][j].Y){//上に伸びてる
            if(lines[i][j].X < lines[i][j+1].X ) dir = 1;
            else dir = 0;
          }else{//下に伸びている
            if(lines[i][j].X > lines[i][j+1].X ) dir = 1;
            else dir = 0;
          }
          len = abs(lines[i][j-1].Y - lines[i][j].Y);
        /*横線*/
        }else{
          if(lines[i][j-1].X < lines[i][j].X){ //右に伸びてる
            if(lines[i][j].Y > lines[i][j+1].Y ) dir = 1;
            else dir = 0;
          }else{//左に伸びている
            if(lines[i][j].Y < lines[i][j+1].Y ) dir = 1;
            else dir = 0;
          }
          len = abs(lines[i][j-1].X - lines[i][j].X);
        }
        data[i][j] = make_pair(len,dir);
      }
      //data[i][0] = make_pair(-1,-1);
      data[i][0] = make_pair(max(abs(lines[i][0].Y-lines[i][1].Y),abs(lines[i][0].X-lines[i][1].X)),-1);
      data[i][m-1] = make_pair(max(abs(lines[i][m-1].Y-lines[i][m-2].Y),abs(lines[i][m-1].X-lines[i][m-2].X)),-1);
    }
    //test
    /*
    REP(i,0,n+1){
      cout<<"i : "<<i<<endl;
      REP(j,0,m){
        cout<<"( "<<data[i][j].first<<", "<<data[i][j].second<<" ), ";
      }
      cout<<endl;
    }
    */
    //check
    REP(i,1,n+1){
      bool flag[] = {true,true};
      REP(j,0,m){
        if(data[0][j] != data[i][j]) flag[0] = false;
      }
      REP(j,1,m-1){
        if(data[0][j].first != data[i][m-j].first ||
          data[0][j].second == data[i][m-j-1].second  ) flag[1] = false;
      }
      if(ms[0] != ms[i]) flag[0]=false, flag[1]=false;
      if(flag[0] || flag[1]) cout<<i<<endl;
    }
    cout<<"+++++"<<endl;
  }
  return 0;
}
