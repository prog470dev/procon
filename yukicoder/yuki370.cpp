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
const long long  LLINF = 1e15;

using namespace std;

int N, M, D[1010];

int main(){
  cin>>N>>M;
  REP(i,0,M) cin>>D[i];
  sort(D,D+M);
  /*
  int ans = INF;
  REP(l,0,M-N+1){
    int tmp;
    if(D[l] < 0 && 0 < D[l+N-1]){
      tmp = (abs(D[l])+D[l+N-1]) + min(abs(D[l]),D[l+N-1]);
    }else{
      if(D[l+N-1] <= 0) tmp = abs(D[l]);
      else tmp = D[l+N-1];
    }
    fprintf(stderr, "tmp: %d\n", tmp);
    ans = min(ans,tmp);
  }
  cout<<ans<<endl;
  */
  vector<int> L, R;
  L.push_back(0);
  R.push_back(0);
  REP(i,0,M){
    if(D[i] < 0) L.push_back(-D[i]);
    else R.push_back(D[i]);
  }
  sort(L.begin(),L.end());
  sort(R.begin(),R.end());
  int ans = INF;
  REP(i,0,min(N+1,(int)L.size())){
    if(N-i < R.size()) ans = min(ans, min(L[i]+R[N-i]*2, L[i]*2+R[N-i]));
  }
  cout<<ans<<endl;
  return 0;
}
