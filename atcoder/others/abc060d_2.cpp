/*
・最終的な和（計算結果）がlonglongに成るものは、
　足していく各要素も、最初からlonglongにしておく。（intにしない！）
*/

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

using namespace std;

int main() {

  int N, W;
  long long w[105], tv;
  vector<long long> v[4];
  cin>>N>>W;
  REP(i,0,N){
    cin>>w[i]>>tv;
    v[w[i]-w[0]].push_back(tv);
  }
  REP(i,0,4){
    sort(v[i].begin(), v[i].end(), greater<long long>());
  }
  long long ans = 0;
  REP(i,0,v[0].size()+1){
    REP(j,0,v[1].size()+1){
      REP(k,0,v[2].size()+1){
        REP(l,0,v[3].size()+1){
          long long sum = 0;
          REP(ii,0,i) sum += v[0][ii];
          REP(ii,0,j) sum += v[1][ii];
          REP(ii,0,k) sum += v[2][ii];
          REP(ii,0,l) sum += v[3][ii];
          if(i*w[0] + j*(w[0]+1) + k*(w[0]+2) + l*(w[0]+3) <= W) ans = max(ans, sum);
        }
      }
    }
  }

  cout<<ans<<endl;

  return 0;
}
