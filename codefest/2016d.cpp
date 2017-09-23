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


int main(){

  string bloks[305];
  int H, W;

  cin>>H>>W;
  REP(i,0,N){
    cin>>blocks[i];
  }

  if(W != 3){
    return 0;
  }

  int ans = 0;
  REP(i,0,H){
    REP(j,0,H-i){
      if(blocks[i][0] == blocks[j][1]) ans++;
      if(blocks[j][2] == blocks[j][1]) ans++;
    }
    for(int j = N-1; 0 < i; j--){
      blocks[j][1] = bloks[j+1][1];
    }
  }

  cout<<ans<<endl;

  return 0;
}
