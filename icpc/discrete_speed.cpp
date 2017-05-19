/*
2017_04_24_AC
<point>
・(いとつ前の町、現在の町、現在の町に到達時の速度)を状態として、ダイクストラ（priority_queue）
<caution>
 ・Uターンの条件が抜けていた。
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
#define D first
#define C second

using namespace std;

const double INF = 1000000000.0;

double d[35][35][35];
bool visited[35][35][35];
int N,M,S,G;
pair<int, int> p[35][35];

struct ST{
  double ti;
  int bn;
  int cn;
  int sp;
  ST(double _ti, int _bn, int _cn, int _sp){
    ti = _ti;
    bn = _bn;
    cn = _cn;
    sp = _sp;
  }

  bool operator >(const ST &e) const{
    return ti > e.ti;
  }

};

int main() {
  while(1){
    cin>>N>>M;
    if(N==0 && M==0) break;
    cin>>S>>G;
    S--; G--;

    REP(i,0,N)REP(j,0,N)REP(k,0,35) d[i][j][k] = INF;
    REP(i,0,N)REP(j,0,N)REP(k,0,35) visited[i][j][k] = false;
    REP(i,0,N)REP(j,0,N) p[i][j].D = p[i][j].C = -1;

    REP(i,0,M){
      int x,y,d,c;
      cin>>x>>y>>d>>c;
      p[x-1][y-1].D = p[y-1][x-1].D = d;
      p[x-1][y-1].C = p[y-1][x-1].C = c;
    }

    d[S][S][0] = 0.0;

    priority_queue< ST, vector<ST>, greater<ST> > PQ;
    ST st(0.0,S,S,0);
    PQ.push(st);

    bool flag = true;
    while(!PQ.empty()){
      ST u = PQ.top(); PQ.pop();
      double mtime = u.ti;
      int ubn=u.bn, ucn=u.cn, usp=u.sp;
      //visited[ubn][ucn][usp] = true;
      if(d[ubn][ucn][usp] < mtime) continue;

      if(ucn == G && usp == 1){
        printf("%.5lf\n",d[ubn][ucn][usp]);
        flag = false;
        break;
      }

      visited[ubn][ucn][usp] = true;
      for(int v = usp-1; v <= usp+1; v++){
        if(v <= 0) continue;
        REP(next,0,N){
          if(/*visited[ucn][next][v] ||*/ p[ucn][next].D == -1 || p[ucn][next].C < v || ucn == next || ubn == next) continue;
          if(d[ucn][next][v] > mtime + (double)p[ucn][next].D/(double)v){
            d[ucn][next][v] = mtime + (double)p[ucn][next].D/(double)v;
            ST tst(d[ucn][next][v], ucn,next,v);
            PQ.push(tst);
          }
        }
      }

    }
    if(flag){
      cout<<"unreachable"<<endl;
    }
  }

  return 0;
}
