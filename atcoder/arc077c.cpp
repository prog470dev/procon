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

int n;
int a[200010];

int main() {
  cin>>n;
  REP(i,0,n) cin>>a[i];

  int l=-1, r=1;
  vector<pair<int,int> > b;
  REP(i,0,n){
    if(i%2==0){
      b.push_back(make_pair(l,a[i]));
      l--;
    }else{
      b.push_back(make_pair(r,a[i]));
      r++;
    }
  }
  sort(b.begin(),b.end());

  if(n%2==0) {
    RREP(i,0,b.size()) cout<<b[i].S<<" ";
  }else{
    REP(i,0,b.size()) cout<<b[i].S<<" ";
  }
  cout<<endl;

  return 0;
}
