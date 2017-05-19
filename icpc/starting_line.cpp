/*
2017_05_10_AC
<point>
・シュミレーション的な貪欲法
・（キープしているニンジンを消費しながら）加速を続けられる間は、進み続け、
　途中でニンジンに出会った場合、基本的にキープするが、
　キープできなかったら、持っている中で一番古いニンジンを捨てて、
　２番目に古いニンジンを使用して、加速を続ける。（キープ数はKのまま）
　※いま出会ったニンジンはキープ
・手持ちのニンジンでは加速できなくなったら、
　現在地から一番近い次のニンジンの位置へワープする。
・最終的に、加速状態で進んだ距離の合計を記録しておき、そこから計算する。
<caution>
・加速中にニンジンに出会い、現在のニンジンの効果を打ち切り、
　キープしているニンジンを一つ消費するとき、
　キューの先頭を次のニンジンに設定した後に、
　たったいまっであったニンジンをpushするのを忘れていた。
　→ 今回はqueueの要素数が異常な値になっていたが、
　　もっと早く様々な要因について出力して調べるべき。
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

int N,K,T,U,V,L,D[10010];

int main() {
  cin>>N>>K>>T>>U>>V>>L;
  REP(i,0,N) cin>>D[i];

  int pos=D[0], vdist=0, di=1, keep=0;
  int diEnd = D[0]+V*T;
  queue<int> dq;

  while(1){
    REP(nowPos,pos,diEnd+1){
      if(nowPos!=pos)vdist++;
      if(nowPos == L)break;
      if(di < N && nowPos == D[di]){
        if(keep < K) keep++, dq.push(di);
        else{
          diEnd = max(nowPos,D[dq.front()]) + V*T;
          dq.pop();
          dq.push(di);
        }
        di++; //uodate next_Di_candidate
      }
      if(nowPos==diEnd && keep>0){
        diEnd = max(nowPos,D[dq.front()]) + V*T;
        dq.pop();
        keep--;
      }
    }
    pos = diEnd+1;
    if(pos >= L) break;

    bool flag = true;
    /*always keep is 0 here*/
    REP(nowPos,pos,L+1){
      if(di < N && D[di] == nowPos){
        pos = D[di];
        diEnd = D[di] + V*T;
        di++;
        //use immediately
        flag = false;
        break;
      }
    }
    if(flag) break;
  }

  double ans = (double)(L-vdist)/(double)U + (double)vdist/(double)V;
  printf("%.8lf\n", ans);

  return 0;
}
