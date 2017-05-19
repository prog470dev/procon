/*
2017_04_27_AC
<point>
・行と列を独立に計算する。
<caution>
・行か列の「どちらか」が埋まっていれば、もう片方も埋まっている。
・２つの塗られている範囲の、反対側の端同士が１違いの値になるとき、
　実際は、その間に塗られていない空間が存在しているが、
　いもす法のところで「端＋１」の部分を-1とすると、その空間がないことになってしまう。
　したがって、「端」の部分で-1として、最後に調べるのは、H-1(W-1)までとする。
　※配列で”線”や”境界”を表現するときの定番の注意点。imosマスは、左側に基準を置かないとバグらせる。
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

int main() {

  int N, W, H;
  long long ximos[100005]={}, yimos[100005]={};
  cin>>N>>W>>H;
  REP(i,0,N){
    int x, y, w;
    cin>>x>>y>>w;
    ximos[max(0,x-w)]++; ximos[min(W,x+w)]--;
    yimos[max(0,y-w)]++; yimos[min(H,y+w)]--;
  }
  REP(i,1,W+1){
    ximos[i] += ximos[i-1];
  }
  REP(i,1,H+1){
    yimos[i] += yimos[i-1];
  }
  int flagx = true, flagy = true;
  REP(i,0,W){
    if(ximos[i] == 0) flagx = false;
  }
  REP(i,0,H){
    if(yimos[i] == 0) flagy = false;
  }

  if(flagx || flagy) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}
