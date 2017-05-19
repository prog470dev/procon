#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {

  int N, p[105], m = 0;

  cin>>N;
  for(int i=0 ;i<N; i++) cin>>p[i], m += p[i];

  int dp[10005][105];
  set<int> s;

  dp[0][0] = 1;
  dp[p[0]][0] = 1;

  for(int j=0; j<=m; j++){
    for(int i=1; i<N; i++){
      if(j >= p[i] && (dp[j][i-1] || dp[j-p[i]][i-1])) dp[j][i] = 1;
      else if(j < p[i] && dp[j][i-1]) dp[j][i] = 1;
      if(dp[j][i] == 1) s.insert(j);  //ここでやらなくてもOK
    }
  }

  cout<<s.size()<<endl;

  return 0;
}
