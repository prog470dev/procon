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
#include <deque>
#include <algorithm>

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long  LLINF = 1e18;

using namespace std;

int N, K;
string A[15];
set<string> ans;
bool use[15];

void dfs(int num, string str){
  if(num == K){
    if(ans.find(str)==ans.end()) ans.insert(str);
    return;
  }
  REP(i,0,N){
    if(use[i]) continue;
    string tmp = str + A[i];
    use[i] = true;
    dfs(num+1, tmp);
    use[i] = false;
  }
}

int main(){
  cin>>N>>K;
  REP(i,0,N) cin>>A[i];
  REP(i,0,N){
    use[i] = true;
    dfs(1,A[i]);
    use[i] = false;
  }
  cout<<ans.size()<<endl;
  return 0;
}
