/*
2017_05_24_AC
<point>
・i回目のとき、番号がnumだとすると、i-1回目のときの番号は
　[0*k-0, 1*k-2] => num + 1
  [1*k-1, 2*k-3] => num + 2
  [2*k-2, 3*k-4] => num + 3
  ......
  [a[0]*k-a[1], a[2]*k-a[3]] => num + a[4]
  ※a[i]は同時に増加する
<caution>
・変数を増加させる場合の増加量は、
　ループでインクリメントしていかなくても、差分からすぐわかる。
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
#define F first
#define S second
#define ll long long;

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

long long N, k, a[5] = {0,0,1,2,1};

int main() {
  cin>>N>>k;
  long long num=0;
  REP(i,0,N-1){
    if(a[0]*k-a[1] > num || num > a[2]*k-a[3]){
      long long inc = (k*a[0]-a[1]-num)/(1-k);
      REP(j,0,5) a[j] += inc;
    }
    num += a[4];
  }
  cout<<num<<endl;
  return 0;
}
