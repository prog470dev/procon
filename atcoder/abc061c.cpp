/*
2017_05_13_AC
<caution>
・最後のところで入力 K (int) と d[i] (longlong)を比較していた。
　比較するときは、必ず「同じ型」にする。
　※よくやりがちなので注意する。
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

using namespace std;

long long d[100010];

int main() {
  long long N,K;
  cin>>N>>K;
  REP(i,0,N){
    int a;
    long long b;
    cin>>a>>b;
    d[a] += b;
  }
  REP(i,1,100010) d[i] += d[i-1];
  REP(i,1,100010){
    //cout<<"d["<<i<<"] : "<<d[i]<<endl;
    if(d[i] >= K){
      cout<<i<<endl;
      return 0;
    }
  }

  return 0;
}
