/*
2017_04_13_AC
・予めDP配列を作っておく方法をとったが、計算量:2*10^8なのでギリギリ。
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

/*dp[i]: 整数iを構成できる最小の正四面体数の個数*/
int dp1[1000005], dp2[1000005];
void makeDP(){
  vector<int> v1;
  vector<int> v2;
  int tn = 1;
  while(1){
      int tmp = tn*(tn+1)*(tn+2)/6;
      if(tmp < 1000000){
        v1.push_back(tmp);
        if(tmp % 2 != 0) v2.push_back(tmp);
      }else{
        break;
      }
      tn++;
  }
  /*1は正四面体数なので、最悪与えられた数自体の個数で構成可能*/
  REP(i,0,1000005) dp1[i] = i, dp2[i] = i;
  REP(i,1,v1.size()){
    REP(j,0,1000005){
      if(j-v1[i] >= 0) dp1[j] = min(dp1[j], dp1[j-v1[i]] + 1);
    }
  }
  REP(i,1,v2.size()){
    REP(j,0,1000005){
      if(j-v2[i] >= 0) dp2[j] = min(dp2[j], dp2[j-v2[i]] + 1);
    }
  }
}

int main() {

  makeDP();

  int N;
  while(1){
    cin>>N;
    if(N==0) break;
    cout<<dp1[N]<<" "<<dp2[N]<<endl;
  }

  return 0;
}
