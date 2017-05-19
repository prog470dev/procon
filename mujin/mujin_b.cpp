/*
2017_02_26_AC
<疑問>
・一行を真っ黒に塗ったと、真っ白な列の本数は本当に変化しないのか？
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
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

const int INF = 1000000000;

int main() {

  int N;
  cin>>N;
  string a[505];
  REP(i,0,N) cin>>a[i];

  int tc = 0;
  REP(i,0,N)REP(j,0,N) if(a[i][j] == '#') tc++;
  if(tc == 0){
    cout<<-1<<endl;
    return 0;
  }

  int ans = INF;
  REP(r,0,N){
    int cnt = 0;
    int tmp = 0;
    REP(i,0,N) if(a[i][r] == '#') tmp++;
    if(tmp==0) cnt++;
    tmp=0;
    REP(j,0,N) if(a[r][j] == '.')tmp++;
    cnt += tmp;
    tmp=0;
    REP(j,0,N){
      int t = 0;
      REP(i,0,N){
        if(a[i][j] == '.') t++;
      }
      if(t != 0) tmp++;
    }
    cnt += tmp;
    ans = min(ans, cnt);
  }

  if(ans==INF) cout<<-1<<endl;
  else cout<<ans<<endl;

  return 0;
}
