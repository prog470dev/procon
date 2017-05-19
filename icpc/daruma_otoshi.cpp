/*
2017_04_01_AC
<point>
・区間DPを使う。dp[l][r]:lからrの範囲で消せる最大ブロック数
<caution>
・両端が条件を満たしていても、その間が”すべて”消せなければ、
　両端は消えない。
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

int main() {

  int n, a[305];
  while(1){
    cin>>n;
    if(n == 0) break;
    REP(i,0,n) cin>>a[i];

    int dp[305][305];
    REP(i,0,n)REP(j,0,n) dp[i][j] = 0;

    for(int k=1; k<n; k++){
      for(int i = 0; i+k<n; i++){
        if(abs(a[i] - a[i+k]) <= 1 && dp[i+1][i+k-1] == k-1){
          /*二つ目の条件がないと、中身が全部消えなくても、両端も消せることになってしまう*/
          dp[i][i+k] = dp[i+1][i+k-1] + 2;
        }else{
          int tmp = 0;
          for(int p=i+1; p<i+k; p++){
            if(p+1 < i+k) tmp = max(tmp, dp[i][p] + dp[p+1][i+k]);
            else tmp = max(tmp, max(dp[i][p], dp[i+k-1][i+k]));
          }
          dp[i][i+k] = tmp;
        }
      }
    }
    cout<<dp[0][n-1]<<endl;
  }


  return 0;
}
