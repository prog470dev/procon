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

    int n, d, x, p[10][10];
    cin>>n>>d>>x;
    REP(i,0,d)REP(j,0,n) cin>>p[i][j];

    int dp[100005];
    int maxMoney = x;

    REP(day,0,d-1){
      REP(i,0,maxMoney+1) dp[i] = i;

      REP(j,0,n){ //select stock
        REP(i,0,maxMoney+1){  //select amount of money
          if(i - p[day][j] >= 0){
            dp[i] = max(dp[i], dp[i - p[day][j]] + p[day+1][j]);
          }
        }
      }

      maxMoney = *max_element(dp, dp+(maxMoney+1));
    }

    cout<<maxMoney<<endl;

  return 0;
}
