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

using namespace std;

long long H,W,ans = 10000000010;

int main() {
  cin>>H>>W;
  //縦に３つ
  if(3 <= H){
    ans = min(ans, (H+3-1)/3*W - H/3*W);
  }
  //横に３つ
  if(3 <= W){
    ans = min(ans, (W+3-1)/3*H - W/3*H);
  }
  //2+1パタン
  REP(i,1,W){
    vector<long long> v;
    v.push_back(i*H);
    v.push_back((H+2-1)/2*(W-i));
    v.push_back(H/2*(W-i));
    sort(v.begin(),v.end());
    ans = min(ans, v[2]-v[0]);
  }
  REP(i,1,H){
    vector<long long> v;
    v.push_back(i*W);
    v.push_back((W+2-1)/2*(H-i));
    v.push_back(W/2*(H-i));
    sort(v.begin(),v.end());
    ans = min(ans, v[2]-v[0]);
  }

  cout<<ans<<endl;
  return 0;
}
