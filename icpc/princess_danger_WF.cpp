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

int N, M, L, K, A, H;
int ans;
bool isfreeze[100];
int v[100][100];

int main() {

  while(1){
    cin>>N>>M>>L>>K>>A>>H;
    if(N==0) break;
    REP(i,0,100) isfreeze[i] = false;
    isfreeze[A] = true;
    isfreeze[H] = true;
    REP(i,0,L){
      int t;
      cin>>t;
      isfreeze[t] = true;
    }
    REP(i,0,100)REP(j,0,100){
      if(i == j) v[i][j] = 0;
      else v[i][j] = INF;
    }
    REP(i,0,K){
      int x, y, t;
      cin>>x>>y>>t;
      v[x][y] = t;
      v[y][x] = t;
    }

    //WF
    REP(k,0,N){
      REP(i,0,N){
        REP(j,0,N){
          v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
        }
      }
    }

    //冷凍施設がある町以外はただの道とみなして、情報を消す。
    //冷凍施設がある町でも、M以内に行けないならば、情報を消す。
    REP(i,0,N){
      REP(j,0,N){
        if(!isfreeze[i] || !isfreeze[j] || v[i][j] > M) v[i][j] = INF;
      }
    }

    //更新されたグラフでWF
    REP(k,0,N){
      REP(i,0,N){
        REP(j,0,N){
          v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
        }
      }
    }

    if(v[A][H] == INF) cout<<"Help!"<<endl;
    else cout<<v[A][H] + max(0,v[A][H]  - M)<<endl;
  }

  return 0;
}
