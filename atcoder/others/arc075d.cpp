/*
2017_06_04_AC
<point>
・条件 check(K) は、ある値 K* を堺に、
 「"K*以上"では条件を満たすが、"K*未満"では条件を満たさない。」という性質がある。
 これは、ソート済み配列 A[.]について,
ある値 A[K*]=key を発見するときの二分探索のルールと同じ構造をしている。（K*を出力したい。）
→ (sum <= k)※今回 == (key <= A[mid])※普通のやつ のイメージ
→ 探したい値よりまだ大きい（or等しい）のだから、少なくともk (mid)までは、
　右端のを絞ることができるだろうって話。
<caution>
・二分探索の継続条件を [r-l>1] とするなら、最終的な答えは右端(r)になる。
・チェック条件関数の和を取る部分で、負に成る場合(オーバーキル)を含めてしまうと、
　正の加算をの数を減らしてしまうので条件が変わってしまう。
　（他の個体のオーバーキルのマイナスで、体力のあまりをカバーできるわけではない。）
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

long long N, A, B, H[100010];

bool check(long long k){
     long long sum = 0;
     REP(i,0,N) sum += max(0LL, (H[i]-k*B+(A-B-1))/(A-B));
     return (sum <= k);
}

int main() {
  cin>>N>>A>>B;
  REP(i,0,N) cin>>H[i];
  long long l = 0, r = 1e9;
  /*
  目的：条件を満たす”最小”のインデックスを見つけたい。（check(K)を満たす最小のK）
  X < Y のとき check(X) を満たすなら check(Y) も満たす。
  */
  while(r-l > 1){
    long long mid = (l+r)/2;
    if(check(mid)) r = mid; //mid以下では必ず条件が満たされる。（少なくともmid以下まで絞ってOK）
    else l = mid;  //mid"以下"で条件を満たすことはない。
  }
  cout<<r<<endl;
  return 0;
}
