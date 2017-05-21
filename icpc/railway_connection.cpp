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
const long long LLINF = 1e15;

using namespace std;

int n,m,c,s,g;
int x,y,d,comp,p[25],q,r[25][55];
vector<pair<int,pair<int,int> > > rail[1010];  //駅、距離、会社
int dp[110][25];  //スタート(s-1,0)から状態（駅番号[0->n-1]、直前に使った駅[1!!->c]）までの最小コスト
                           //直前の会社=0 は、スタートの時のみ（駅は１始まりインデックスを最小）
vector<pair<pair<int,int>,int > > compCost[25];//<<距離区間>,r>

int main() {
  while(1){
    cin>>n>>m>>c>>s>>g;
    if(n==0&&m==0&&c==0&&s==0&&g==0) break;
    REP(i,0,m){
      cin>>x>>y>>d>>comp;
      rail[x-1].push_back(make_pair(y-1, make_pair(d,comp-1)));
      rail[y-1].push_back(make_pair(x-1, make_pair(d,comp-1)));
    }
    REP(i,0,c) cin>>p[i];
    REP(i,0,c){
      compCost[i].push_back(make_pair(make_pair(0,INF),INF));
      REP(j,0,p[i]-1){
        cin>>q;
        compCost[i][j].F.S = q;
        compCost[i].push_back(make_pair(make_pair(q,INF),INF));
      }
      REP(j,0,p[i]){
        cin>>r[i][j];
        if(j>0) compCost[i][j].S = compCost[i][j-1].S +  r[i][j]*(compCost[i][j].F.S - compCost[i][j].F.F);
        else compCost[i][j].S = r[i][j]*(compCost[i][j].F.S - compCost[i][j].F.F);
      }
    }

    REP(i,0,n)REP(j,0,c) dp[i][j] = INF;

    //<<距離>,<駅,<直前の会社,"その会社で"走ってきた距離>>>
    priority_queue< pair< int, pair<int,pair<int,int> > > > PQ;
    PQ.push(make_pair(0, make_pair(s-1,make_pair(0,0))));
    REP(i,0,c) dp[s-1][i] = 0;

    while(!PQ.empty()){
      int nowNode = PQ.top().S.F;
      int nowComp = PQ.top().S.S.F;
      int nowDist = PQ.top().S.S.S; //会社nowCompで走ってきた距離
      int nowCost = (-1)*PQ.top().F;
      PQ.pop();
      if(dp[nowNode][nowComp] < nowCost) continue;

      cout<<"nowNode:"<<nowNode<<"(nowCost:"<<nowCost<<")"<<endl;

      REP(i,0,rail[nowNode].size()){
        int nextNode = rail[nowNode][i].F;
        int nextComp = rail[nowNode][i].S.S;

        int nextDist; //"nextComp"で走る距離(個々まで距離を含める場合もある)
        if(nowComp==nextComp) nextDist = nowDist + rail[nowNode][i].S.F;
        else nextDist = rail[nowNode][i].S.F;

        cout<<"---nextNode : "<<nextNode<<", nextDist : "<<nextDist<<"("<<rail[nowNode][i].S.F<<")"<<endl;

        int nextCost=0; //線路がつながっているから、何かしらの値は必ずある
        REP(j,0,compCost[nextComp].size()){
          if(nextDist <= compCost[nextComp][j].F.F) break;
          if(j<compCost[nextComp].size()-1) nextCost += r[nextComp][j]*min(nextDist-compCost[nextComp][j].F.F, compCost[nextComp][j].F.S-compCost[nextComp][j].F.F);
          else nextCost += r[nextComp][j]*(nextDist-compCost[nextComp][j].F.F);
          cout<<"------>>>"<<nextDist-compCost[nextComp][j].F.F<<", "<<compCost[nextComp][j].F.S-compCost[nextComp][j].F.F<<", r:"<<r[nextComp][j]<<endl;
        }
        int tmpCost=0; //重複を差し引くため
        REP(j,0,compCost[nextComp].size()){
          if(nowDist <= compCost[nextComp][j].F.F) break;
          if(j<compCost[nextComp].size()-1) tmpCost += r[nextComp][j]*min(nowDist-compCost[nextComp][j].F.F, compCost[nextComp][j].F.S-compCost[nextComp][j].F.F);
          else tmpCost += r[nextComp][j]*(nowDist-compCost[nextComp][j].F.F);
        }
        if(nowComp==nextComp) nextCost -= tmpCost;

        if(nowComp==nextComp)cout<<"(tmpCost:"<<tmpCost<<")"<<endl;
        cout<<"------nextCost: "<<nextCost<<", dp[nextNode][nextComp]: "<<dp[nextNode][nextComp]<<endl;

        if(nowCost+nextCost < dp[nextNode][nextComp]){
          dp[nextNode][nextComp] = nowCost+nextCost;
          PQ.push(make_pair((-1)*dp[nextNode][nextComp], make_pair(nextNode, make_pair(nextComp,nextDist))));
          cout<<"PUSH!!"<<endl;
        }

      }
    }

    int mincost = INF;
    REP(j,0,c) mincost = min(mincost,dp[g-1][j]);

    if(mincost==INF) cout<<-1<<endl;
    else cout<<mincost<<endl;

  }

  return 0;
}
