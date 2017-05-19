//どうしたらもうゴールは無理だとわかる？
//-> 同じ街, 同じlimitで、以前より大きいステップ数で訪れる必要なし

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
int visited[100][100];
vector< pair<int, int> > tv[100];
vector< pair<int, int> > v[10100];  /*100個の町＊０〜１００の残り時間*/

int maping[100][101];

/*新しいグラフが作れない！！！！
　少なくとも、本番中には作れない！！！
*/

void makeGraph(){
  REP(i,0,N*(M+1)) v[i].clear();

  REP(i,0,N){
    REP(j,0,M+1){
      maping[i][j] = i*N + j; /*町iの残り時間jのノード番号はmaping[i][j]*/
    }
  }

  REP(i,0,N){
    REP(j,0,M+1){
      REP(k,0,v[i].size()){
        if((0 <= j - tv[i][k].second){
          tv[maping[i][j]].push_back(make_pair(maping[tv[i][k].first][j - tv[i][k].second], tv[i][k].second));
          tv[maping[tv[i][k].first][j - tv[i][k].second]].push_back(make_pair([maping[i][j]], tv[i][k].second));
        }
      }
    }
    if(isfreeze[i]){
      REP(t,0,M){
        REP(j,0,M+1){
          REP(k,0,v[i].size()){
            if((0 <= j - tv[i][k].second + t && j + t <= M){
              tv[maping[i][j]].push_back(make_pair(maping[tv[i][k].first][j - tv[i][k].second], tv[i][k].second));
              tv[maping[tv[i][k].first][j - tv[i][k].second]].push_back(make_pair([maping[i][j]], tv[i][k].second));
            }
          }
      }
    }
  }
}

int main() {

  while(1){
    cin>>N>>M>>L>>K>>A>>H;
    if(N==0) break;
    REP(i,0,100) isfreeze[i] = false;
    isfreeze[A] = true;
    isfreeze[H] = true;  //ゴールだからいらないかも？
    REP(i,0,L){
      int t;
      cin>>t;
      isfreeze[t] = true;
    }
    REP(i,0,100) v[i].clear();
    REP(i,0,K){
      int x, y, t;
      cin>>x>>y>>t;
      tv[x].push_back(make_pair(y, t));
      tv[y].push_back(make_pair(x, t));
    }

    ans = INF;
    REP(i,0,100)REP(j,0,100) visited[i][j] = INF;

    dfs(A, M, 0);

    if(ans == INF) cout<<"Help!"<<endl;
    else cout<<ans<<endl;
  }

  return 0;
}
