/*
・DP配列の初期化ミス
・最後のチェックでの「K-tmp」でアンダーフロー
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

bool dp[405][405];

int main() {

  int N, K, a[405];
  long long tsum = 0;
  cin>>N>>K;
  if(N>400 || K>400) return 0;
  REP(i,0,N){
    cin>>a[i];
    tsum += a[i];
  }

  int ans = N;

  REP(i,0,N){
    int tmp = a[i];
    a[i] = 0;

    REP(i,0,405)REP(j,0,405) dp[i][j] = false;
    REP(j,0,N+1) dp[j][0] = true;
    REP(j,0,K-1) if(a[0] == j) dp[1][j] = true;

    REP(j,2,N+1){
      REP(l,0,K){
        if(dp[j-1][l]) dp[j][l] = true;
        if(l-a[(j-1)] >= 0){
          if(dp[j-1][l-a[(j-1)]]){
            dp[j][l] = true;
          }
        }
      }
    }
/*
    cout<<"a["<<i<<"]: "<<tmp<<endl;
    REP(j,0,N+1){
      REP(l,0,K){
        cout<<dp[j][l]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
*/
    bool flag = false;
    REP(j,max(0, K-tmp),K){
      if(dp[N][j]) flag = true;
    }
    if(flag) ans--;
    a[i] = tmp;
  }

  cout<<ans<<endl;

  return 0;
}
