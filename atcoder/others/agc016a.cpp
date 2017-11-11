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

set<int> dp[26];

string S;

int main() {
  cin>>S;
  int cnt = 0;
  while(1){
    REP(i,0,S.size()){
      dp[S[i]-'a'].insert(max(0, i-cnt));
    }
    REP(i,0,26){
      bool flag = true;
      REP(j,0,S.size()-cnt){
        if(dp[i].find(j) == dp[i].end())flag = false;
      }
      if(flag){
        cout<<cnt<<endl;
        return 0;
      }
    }
    cnt++;
  }
  return 0;
}
