/*
2017_06_03_AC
<point>
・回数制限はなく、各文字は０個か２個なので、
　順番を考えずに消せるときに消していけば良い。
・押す位置を基準に刷るのではなく、文字ごとに見ていくと、
　探索回数が少なくて済む。
<caution>
・２点間の間が”空”しかない等、色んな場所で繰り返す単純作業は、
　多少面倒くさくても関数化しておかないと、コードの見通しが悪くなり、重要な部分を見落とす。
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

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long;

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int H, W;
string S[510];

struct posi{
  int y;
  int x;
  posi(int _y, int _x){
    y = _y;
    x = _x;
  }
};

vector<pair< char, pair<posi, posi> > > v;
set<char> st;

bool ck_row(int lx, int rx, int ly, int ry){
  if(rx-lx == 1 && ly == ry) return false;
  REP(j,lx+1,rx){
    if(S[ly][j] != '.'){
      return false;
    }
  }
  return true;
}

bool ck_col(int ly, int ry, int lx, int rx){
  if(ry-ly == 1 && lx == rx) return false;
  REP(i,ly+1,ry){
    if(S[i][lx] != '.'){
      return false;
    }
  }
  return true;
}

int main() {
  cin>>H>>W;
  REP(i,0,H){
    cin>>S[i];
  }

  REP(k,0,26){
    vector<posi> tv;
    REP(i,0,H){
      REP(j,0,W){
        if(S[i][j] == 'A' + k){
          tv.push_back(posi(i,j));
        }
      }
    }
    if(tv.size() == 2){
      v.push_back(make_pair('A'+k, make_pair(tv[0],tv[1])));
    }
  }

  int ans = 0;
  while(1){
    bool flag = true;
    REP(k,0,v.size()){
      if(st.find(v[k].F) != st.end()) continue;
      /*横並び*/
      if(v[k].S.F.y == v[k].S.S.y){
        int fixy = v[k].S.F.y;
        int lx = min(v[k].S.F.x, v[k].S.S.x);
        int rx = max(v[k].S.F.x, v[k].S.S.x);
        if(ck_row(lx,rx,fixy,fixy)){
          S[fixy][lx] = S[fixy][rx] = '.';
          ans += 2;
          flag = false;
          st.insert(v[k].F);
        }
      /*縦並び*/
      }else if(v[k].S.F.x == v[k].S.S.x){
        int fixx = v[k].S.F.x;
        int ly = min(v[k].S.F.y, v[k].S.S.y);
        int ry = max(v[k].S.F.y, v[k].S.S.y);
        if(ck_col(ly,ry,fixx,fixx)){
          S[ly][fixx] = S[ry][fixx] = '.';
          ans += 2;
          flag = false;
          st.insert(v[k].F);
        }
      /*斜め*/
      }else{
        //v[k].S.Fは必ず上側！！
        if(v[k].S.F.x < v[k].S.S.x){
          //左下を起点にする
          if(S[v[k].S.S.y][v[k].S.F.x] == '.'){
            if(ck_row(v[k].S.F.x,v[k].S.S.x,v[k].S.S.y,v[k].S.F.y)
                && ck_col(v[k].S.F.y,v[k].S.S.y,v[k].S.F.x,v[k].S.S.x)){
              S[v[k].S.F.y][v[k].S.F.x] = S[v[k].S.S.y][v[k].S.S.x] = '.';
              ans += 2;
              flag = false;
              st.insert(v[k].F);
              continue;
            }
          }
          //右下を起点にする
          if(S[v[k].S.F.y][v[k].S.S.x] == '.'){
            if(ck_row(v[k].S.F.x,v[k].S.S.x,v[k].S.F.y,v[k].S.S.y)
                && ck_col(v[k].S.F.y,v[k].S.S.y,v[k].S.S.x,v[k].S.F.x)){
              S[v[k].S.F.y][v[k].S.F.x] = S[v[k].S.S.y][v[k].S.S.x] = '.';
              ans += 2;
              flag = false;
              st.insert(v[k].F);
              continue;
            }
          }
        }else{
          //左上を起点にする
          if(S[v[k].S.F.y][v[k].S.S.x] == '.') {
            if(ck_row(v[k].S.S.x,v[k].S.F.x,v[k].S.F.y,v[k].S.S.y)
                && ck_col(v[k].S.F.y,v[k].S.S.y,v[k].S.S.x,v[k].S.F.x)){
              S[v[k].S.F.y][v[k].S.F.x] = S[v[k].S.S.y][v[k].S.S.x] = '.';
              ans += 2;
              flag = false;
              st.insert(v[k].F);
              continue;
            }
          }
          //右下を起点にする
          if(S[v[k].S.S.y][v[k].S.F.x] == '.'){
            if(ck_row(v[k].S.S.x,v[k].S.F.x,v[k].S.S.y,v[k].S.F.y)
                && ck_col(v[k].S.F.y,v[k].S.S.y,v[k].S.F.x,v[k].S.S.x)){
              S[v[k].S.F.y][v[k].S.F.x] = S[v[k].S.S.y][v[k].S.S.x] = '.';
              ans += 2;
              flag = false;
              st.insert(v[k].F);
              continue;
            }
          }
        }
      }
    }
    if(flag) break;
  }

  cout<<ans<<endl;

  return 0;
}
