#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {

  string T;
  cin>>T;

  int dp[100005];
  fill(dp, dp+100005, 0);

  for(int i=0; i<T.size()-1; i++){
    if((T[i] == '2' || T[i] == '?') && (T[i+1] == '?' || T[i+1] == '5')){
      //dp[i+2] = max(dp[i+2], dp[i]+2);
      dp[i+2] = dp[i]+2;
    }
  }


  int ans = 0;
  for(int i=0; i<T.size()+1; i++) {
    //cout<<dp[i]<<" ";
    ans = max(ans, dp[i]);
  }
  //cout<<endl;

  cout<<ans<<endl;



  return 0;
}
