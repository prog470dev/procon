/*
2017_02_27_AC
＜ポイント＞
・再帰関数で、配列を引数に渡すときは、一旦構造体にする。
　そうしないと参照渡しになって、元の状態に戻ってこれなくなる。
　（ただし、dfs()内でpaint()を呼ぶ際は、paint()から出てきたあと、
　　実際に塗った分の変化がないとだめなので、一旦生の配列にコピーして渡し、
  　その後、また構造体にコピーしている。checkは引数の配列を変化させる必要がない値渡し。）
  =>構造体使わなくても、dfs()の中で、塗った後に２次元配列の「コピー」をを作って、
  　再帰関数の引数に渡してやればいいだけでは？（元の配列は変化しない）
    実際、現行のコードでも、「構造体->配列->構造体」としているが、
    もともと与えられた情報は書き換わっているので同じでは？
・関数の定義では引数が(x, y)の順なのに、実際に呼ぶときは(i(=y),j(=x))で渡していた。
　=> どんなときでも((y(=i),x(=j)))の順で固定する。※２次元配列がこの順だから。
＜疑問＞
・他のひとの提出は、もっと実行時間が早い。どうやっている？
＜感想＞
・「再帰」に対して、何か感覚的なものを掴みつつある気がする。
  これは、内容の近い問題をときまくっているせいなので、この方針で続けたい。
  再帰を使う全探索はすべての基本なので、何も考えず書けるようにしておきたい。
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
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

struct S{
  int A[9][9];
};

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int h, w, c, p[9][9], colcnt, ans;
bool visit[9][9];

void paint(int bfcolor, int x, int y,int color, int tp[9][9]){
  visit[y][x] = true;
  bfcolor = tp[y][x];
  tp[y][x] = color;
  REP(k,0,4){
    int posx = x + dx[k];
    int posy = y + dy[k];
    if(!CH(posx,0,w) || !CH(posy,0,h)) continue;
    if(tp[posy][posx] != bfcolor || visit[posy][posx]) continue;
    paint(bfcolor, posx, posy, color, tp);
  }
  return ;
}

void check(int x, int y, int color, struct S s){
  visit[y][x] = true;
  colcnt++;
  REP(k,0,4){
    int posx = x + dx[k];
    int posy = y + dy[k];
    if(!CH(posx,0,w) || !CH(posy,0,h)) continue;
    if(s.A[posy][posx] != color || visit[posy][posx]) continue;
    check(posx, posy, color, s);
  }
  return ;
}

void dfs(int k, int turn, struct S s){

  //塗る
  int tp[9][9];
  REP(i,0,h)REP(j,0,w) tp[i][j] = s.A[i][j];  //ポインタで渡さないと塗られない
  REP(i,0,h)REP(j,0,w) visit[i][j] = false;
  paint(s.A[0][0],0,0,k,tp);
  REP(i,0,h)REP(j,0,w) s.A[i][j] = tp[i][j]; //考えている配列に反映

  //指定色パネルの最大値カウント
  /*
  REP(i,0,h)REP(j,0,w){
    colcnt = 0;
    if(s.A[i][j]==c){
      REP(ii,0,h)REP(jj,0,w) visit[ii][jj] = false;
      check(j,i,c,s);
    }
    ans = max(ans, colcnt);
  }
  if(turn == 5){
    return;
  }
  */
  //三回色変化(1,2,3)と5回色変化(1,2,2,2,3)は同じ事なのでturn==5のみでOK.
  if(turn == 5){
    REP(i,0,h)REP(j,0,w){
      colcnt = 0;
      if(s.A[i][j]==c){
        REP(ii,0,h)REP(jj,0,w) visit[ii][jj] = false;
        check(j,i,c,s);
      }
      ans = max(ans, colcnt);
    }
    return;
  }



  REP(kk,1,7){ //同じ色に変えるのは？
    int bcol = s.A[0][0];
    dfs(kk,turn + 1,s);
  }

  return;
}

int main() {

while(1){
    cin>>h>>w>>c;
    if(h==0 && w==0 && c==0) break;
    REP(i,0,h)REP(j,0,w) cin>>p[i][j];

    ans = 0;
    S sc;
    REP(i,0,h)REP(j,0,w) sc.A[i][j] = p[i][j];

    REP(k,1,7) dfs(k,1,sc);

    cout<<ans<<endl;
  }

  return 0;
}
