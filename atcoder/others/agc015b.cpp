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

string S;
long long imos[100010];

int main() {
  cin>>S;
  REP(i,0,S.size()){
    if(S[i] == 'U'){
      imos[i+1]++;
      imos[S.size()]--;
      imos[0] += 2;
      imos[i] -= 2;
    }else{
      imos[i+1] += 2;
      imos[S.size()] -= 2;
      imos[0]++;
      imos[i]--;
    }
  }
  long long ans = 0;
  REP(i,0,S.size()){
    if(i>0) imos[i] += imos[i-1];
    ans += imos[i];
  }

  cout<<ans<<endl;

  return 0;
}
