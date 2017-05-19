/*
2017_03_02_AC
＜ポイント＞
・次ステップに試す分母iはAまでやる必要ない、ここまでの分母の積*iがAを超えない範囲でよい。
・約分する必要はない。したがって、(a/b)+(c/d)なら(a*d+c*b)/(b*d)とするだけで良い。
　（こうしないとLTE）
・判定は、分子分母を直接比較するのでなく、比で確認する。
・単位分数だから、計算方法は、
　(sum/pro) + (1/i) = (sum*d+pro)/(pro*i)
	しかないので、無駄な前処理とかいらない。
＜疑問＞
・pairはどれくらい遅い？
・約分しなくて本当に大丈夫？
　＝＞問題として、「分割した単位分数の分母の積」がA以下という条件なので、
　　　積proは、単純に掛けていくだけで何もしなくて良い。
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

int P,Q,A,N,ans;

void dfs(int term, int minnum, int prod, int sum){
  if(A < prod || N < term) return;
	if(sum*Q == prod*P){  /* (sum/prod) = (P/Q) の切り下げ対策 */
	  ans++;
		return;
	}
	for(int i=minnum; prod*i <= A; i++){ /* 次に足す単位分数について、小さい方からすべて試す。ただし、minnum以上 */
    dfs(term + 1, i, prod*i, sum*i + prod); /* いつでも (sum/prod)+(1/i)=(sum*i+prod)/(prod*i) が成り立つ */
  }
  return;
}

int main() {
  while(1){
    cin>>P>>Q>>A>>N;
    if(P==0&&Q==0&&A==0&&N==0) break;
    ans = 0;

    //REP(i,1,A+1){   /* １手目(最小分母)だけ決めてやる */
    //  dfs(1,i,i,1);
    //}
    dfs(0,1,1,0); /* 項数 0, 初期分子 0 で設定すると初期値を決めてやらなくて良い */

    cout<<ans<<endl;
  }
  return 0;
}
