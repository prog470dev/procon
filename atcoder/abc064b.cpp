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

int main() {
  int N, a[105];
  cin>>N;
  vector<int> v;
  REP(i,0,N){
    int tmp;
    cin>>tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  cout<<v[v.size()-1] - v[0]<<endl;
  return 0;
}
