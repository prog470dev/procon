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

int N;
int ans = INF;

struct S{
  string A[4];
};

void f(int i, int j, struct S a){
  char t[4];
  REP(col,0,N) t[col] = a.A[i][col];
  REP(row,0,N) a.A[row][j] = t[row];
}

int check(struct S a){
  int cnt = 0;
  REP(i,0,N)REP(j,0,N) if(a.A[i][j] == '#')cnt++;
  return cnt;
}

void dfs(int ii, int  jj, int turn, struct S a){

  if(turn >= 6) return; //??
  if(check(a) == N*N){
    ans = min(ans, turn);
    return;
  }else if(check(a) == 0){
    return;
  }

  REP(i,0,N){
    REP(j,0,N){
      char t[4], bc[4], br[4];

      REP(col,0,N) bc[col] = a.A[i][col];
      REP(row,0,N) br[row] = a.A[row][j];

      REP(col,0,N) t[col] = a.A[i][col];
      REP(row,0,N) a.A[row][j] = t[row];
      dfs(i, j, turn + 1, a);

      REP(col,0,N) a.A[i][col] = bc[col];
      REP(row,0,N) a.A[row][j] = br[row];

    }
  }
  return;
}


int main() {

  //string A[4];
  S s;

  cin>>N;
  if(N > 3) return 0;
  REP(i,0,N){
    cin>>s.A[i];
  }

  ans = INF;

  REP(i,0,N)REP(j,0,N) dfs(i, j, 0, s);

  if(ans != INF) cout<<ans<<endl;
  else cout<<-1<<endl;

  return 0;
}
