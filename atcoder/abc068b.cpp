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
#include <utility>

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long  LLINF = 1e18;

using namespace std;


/*==================================================*/

/*==================================================*/

int N;

int main(){

  cin>>N;
  int ans = 1, ta = 0;
  for(int i = N; 0 <= i; i--){
    int t = i;
    int cnt = 0;
    while(t % 2 == 0 && t > 0){
      cnt++;
      t /= 2;
    }
    if(ta < cnt ){
      ans = i;
      ta = cnt;
    }
  }

  cout<<ans<<endl;

  return 0;
}
