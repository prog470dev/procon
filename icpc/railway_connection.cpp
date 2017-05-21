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
int dp[110][25][2000010];  //スタート(s-1,0)から状態（駅番号[0->n-1]、直前に使った駅[1!!->c]）までの最小コスト
                           //直前の会社=0 は、スタートの時のみ（駅は１始まりインデックスを最小）
vector<pair<pair<int,int>,int > > compCost[25];//<<距離区間>,r>

int main() {
  while(1){
    cin>>n>>m>>c>>s>>g;
    if(n==0&&m==0&&c==0&&s==0&&g==0) break;
    REP(i,0,m){
      cin>>x>>y>>d>>comp;
      rail[x-1].push_back(make_pair(y-1, make_pair(d,comp)));
      rail[y-1].push_back(make_pair(x-1, make_pair(d,comp)));
    }
    REP(i,1,c+1) cin>>p[i];
    REP(i,1,c+1){
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

    REP(i,0,n)REP(j,0,c)REP(k,0,2000010) dp[i][j][k] = INF;

    //<<距離>,<駅,<直前の会社,"その会社で"走ってきた距離>>>
    priority_queue< pair< int, pair<int,pair<int,int> > > > PQ;
    PQ.push(make_pair(0, make_pair(s-1,make_pair(0,0))));
    dp[s-1][0][0] = 0;

    while(!PQ.empty()){
      int nowNode = PQ.top().S.F;
      int nowComp = PQ.top().S.S.F;
      int nowDist = PQ.top().S.S.S; //会社nowCompで走ってきた距離
      int nowCost = PQ.top().F;
      PQ.pop();
      if(dp[nowNode][nowComp][nowDist] < nowCost) continue;

      cout<<"nowNode:"<<nowNode<<endl;

      REP(i,0,rail[nowNode].size()){
        int nextNode = rail[nowNode][i].F;
        int nextComp = rail[nowNode][i].S.S;

        int nextDist;// = rail[nowNode][i].S.F;
        if(nowComp==nextComp) nextDist = nowDist + rail[nowNode][i].S.F;
        else nextDist = rail[nowNode][i].S.F;

        int tmpCost=0;//直前までの会社で走った距離にかかったコスト
        REP(i,0,compCost[nowComp].size()){
          if(compCost[nowComp][i].F.F <= nowDist && nowDist <= compCost[nowComp][i].F.S){
            if(i>0) tmpCost = compCost[nowComp][i-1].S + r[nowComp][i]*(nowDist- compCost[nowComp][i].F.F);
            else tmpCost = r[nowComp][i]*(nowDist- compCost[nowComp][i].F.F);
            break;
          }
        }

        int nextCost=0; //線路がつながっているから、何かしらの値は必ずある
        REP(i,0,compCost[nextComp].size()){
          if(compCost[nextComp][i].F.F <= nextDist && nextDist <= compCost[nextComp][i].F.S){
            if(i>0) nextCost = compCost[nextComp][i-1].S + r[nextComp][i]*(nextDist- compCost[nextComp][i].F.F);
            else nextCost = r[nextComp][i]*(nextDist- compCost[nextComp][i].F.F);
            if(nowComp!=nextCost)cout<<">> nextNode:"<<nextNode<<", nextDist:"<<nextDist<<", nextCost"<<nextCost<<endl;
            break;
          }
        }

        if(nowComp==nextComp){
          if(nowCost+nextCost-tmpCost < dp[nextNode][nextComp][nextDist]){
            dp[nextNode][nextComp][nextDist] = nowCost+nextCost-tmpCost;  //nextConsrに以前の走行のコストも入れてしまっている
            //cout<<"--- nextNode:"<<nextNode<<", dp[nextNode][nextComp][nextDist]:"<<dp[nextNode][nextComp][nextDist]<<endl;
            PQ.push(make_pair(dp[nextNode][nextComp][nextDist], make_pair(nextNode, make_pair(nextComp,nextDist))));
          }
        }else{
          if(nowCost+nextCost < dp[nextNode][nextComp][nextDist]){
            dp[nextNode][nextComp][nextDist] = nowCost+nextCost;
            //cout<<"--- nextNode:"<<nextNode<<", dp[nextNode][nextComp][nextDist]:"<<dp[nextNode][nextComp][nextDist]<<endl;
            PQ.push(make_pair(dp[nextNode][nextComp][nextDist], make_pair(nextNode, make_pair(nextComp,nextDist))));
          }
        }

      }
    }

    int mincost = INF;
    REP(i,1,c)REP(j,0,2000010) mincost = dp[g-1][i][j];

    if(mincost==INF) cout<<-1<<endl;
    else cout<<mincost<<endl;

  }

  return 0;
}
