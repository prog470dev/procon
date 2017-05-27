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

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long;

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int dhandy[4][4] = {{-1,-1,0,1},{0,1,1,1},{1,1,0,-1},{0,-1,-1,-1}};
int dhandx[4][4] = {{0,1,1,1},{1,1,0,-1},{0,-1,-1,-1},{-1,-1,0,1}};
char startmark[4] = {'^','>','v','<'};

string field[55];

int d[55][55][4][4];
bool visit[55][55];
int N, M, sy, sx, sdir, gy, gx;
int ans = INF;

void dfs(int y, int x, int dir, int hand, int cnt){
  //cout<<"y:"<<y<<", x:"<<x<<"( dir:"<<dir<<", hand:"<<hand<<", cnt:"<<cnt<<")"<<endl;
  if(y==gy && x==gx){
    ans = min(ans, cnt);
    return;
  }
  //同じ状態ですでにより良いケースがあるなら探索しない。
  if(d[y][x][dir][hand] <= cnt) return;
  d[y][x][dir][hand] = cnt;

  REP(k,0,3){
    if(k == 0){ //前進
      if(((dir==0 || dir==2) && !CK(y + dy[dir],0,N)) || ((dir==1 || dir==3) && !CK(x + dx[dir],0,M))) continue;
      if(((dir==0 || dir==2) && field[y + dy[dir]][x]=='#') || ((dir==1 || dir==3) && field[y][x + dx[dir]]=='#')) continue;
      //現在の手の位置から前方へ見ていく
      for(int i = hand; 0 <= i; i--){
        int nexthandy = y + dhandy[dir][i], nexthandx = x + dhandx[dir][i];
        if(!CK(nexthandy,0,N) || !CK(nexthandx,0,M)){
          //右後の壁に手があると前に進めない
          if(i >= 3) continue;
          if(visit[y+dy[dir]][x+dx[dir]]){
            dfs(y+dy[dir], x+dx[dir], dir, i+1, cnt);
          }else{
            visit[y+dy[dir]][x+dx[dir]] = true;
            dfs(y+dy[dir], x+dx[dir], dir, i+1, cnt+1);
            visit[y+dy[dir]][x+dx[dir]] = false;
          }
        }else if(field[nexthandy][nexthandx]=='#'){ //このように分けないと範囲外アクセスになる（いい方法はアリそう）
          if(i >= 3) continue;
          if(visit[y+dy[dir]][x+dx[dir]]){
            dfs(y+dy[dir], x+dx[dir], dir, i+1, cnt);
          }else{
            visit[y+dy[dir]][x+dx[dir]] = true;
            dfs(y+dy[dir], x+dx[dir], dir, i+1, cnt+1);
            visit[y+dy[dir]][x+dx[dir]] = false;
          }
        }else{
          if(i!=1) break;  //途中で壁を触れなくなったらアウト
        }
      }
    }else if(k == 1){ //右回り
      for(int i = hand; i < 4; i++){
        int nexthandy = y + dhandy[dir][i], nexthandx = x + dhandx[dir][i];
        if(!CK(nexthandy,0,N) || !CK(nexthandx,0,M)){
          if(i < 2) continue;
          dfs(y, x, (dir+1)%4, i-2, cnt);
        }else if(field[nexthandy][nexthandx]=='#'){
          if(i < 2) continue;
          dfs(y, x, (dir+1)%4, i-2, cnt);
        }else{
          if(i!=1) break;
        }
      }
    }else{  //左回り
      for(int i = hand; 0 <= i; i--){
        int nexthandy = y + dhandy[dir][i], nexthandx = x + dhandx[dir][i];
        if(!CK(nexthandy,0,N) || !CK(nexthandx,0,M)){
          if(i >= 2) continue;
          dfs(y, x, (dir-1+40)%4, i+2, cnt);
        }else if(field[nexthandy][nexthandx]=='#'){
          if(i >= 2) continue;
          dfs(y, x, (dir-1+40)%4, i+2, cnt);
        }else{
          if(i!=1) break;
        }
      }
    }
  }
}

int main() {
  cin>>N>>M;
  REP(i,0,N){
    cin>>field[i];
    REP(j,0,M){
      if(field[i][j] == 'G'){
        gy = i;
        gx = j;
      }
      REP(k,0,4){
        if(field[i][j] == startmark[k]){
          sdir = k;
          sy = i;
          sx = j;
        }
      }
    }
  }

  REP(i,0,N)REP(j,0,M)REP(k,0,4)REP(l,0,4) d[i][j][k][l] = INF;
  REP(i,0,N)REP(j,0,M) visit[i][j] = false;
  visit[sy][sx] = true;

  dfs(sy, sx, sdir, 2, 1);

  if(ans == INF) cout<<-1<<endl;
  else cout<<ans<<endl;

  return 0;
}
