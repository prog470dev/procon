/*
・ノードのみを状態として、ダイクストラ法をし、
　経路上の長い道から順に頭数の多い場車券を割り当てる嘘解法
・場車券の残りも、状態として考慮してやればダイクストラのみで解答可能のはず。
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
#define F first
#define S second

using namespace std;

const double INF = 1e9;

int N, M, P, A, B;
double t[10], road[35][35];

int main() {

  while(1){
    cin>>N>>M>>P>>A>>B;
    if(N==0) break;
    REP(i,0,N) cin>>t[i];
    REP(i,0,M)REP(j,0,M) road[i][j] = INF;
    REP(i,0,P){
      int x, y;
      double z;
      cin>>x>>y>>z;
      x--; y--;
      road[x][y] = road[y][x] = z;
    }

    priority_queue< pair< double, pair<int, int> > > PQ;//<最短距離 ,<ノード番号、通った道の数>>
    pair<double, int> d[35]; //<最短距離 ,通った道の数>
    int from[35]; //どこから来たか

    REP(i,0,M) from[i] = -1;
    REP(i,0,M) d[i].F = INF, d[i].S = 0;
    d[A-1].F = 0.0;
    PQ.push(make_pair(0.0, make_pair(A-1,0)));
    //start_Dijikstra
    while(!PQ.empty()){
      int nowNode = PQ.top().S.F;
      int nowCnt = PQ.top().S.S;
      double nowDist = PQ.top().F;
      PQ.pop();

      if(d[nowNode].F < nowDist) continue;

      REP(nextNode,0,M){
        if(road[nowNode][nextNode] == INF) continue;
        if(d[nextNode].F > nowDist + road[nowNode][nextNode] && nowCnt + 1 <= N){
          d[nextNode].F = nowDist + road[nowNode][nextNode];
          d[nextNode].S = nowCnt + 1; //これいる？
          from[nextNode] = nowNode;
          PQ.push(make_pair(d[nextNode].F, make_pair(nextNode,nowCnt + 1)));
        }
      }

    }
    //end_Dijikstra
    vector<int> nodes;
    int node = B-1;
    bool flag = false;
    while(1){
      nodes.push_back(node);
      if(node == A-1) break;
      node = from[node];
      if(node == -1){
        cout<<"Impossible"<<endl;
        //return 0;
        flag = true;
        break;
      }
    }
    if(flag) continue;

    vector<double> dist;
    REP(i,0,nodes.size()-1){
      dist.push_back(road[nodes[i]][nodes[i+1]]);
    }
    sort(dist.begin(), dist.end(), greater<double>());
    sort(t, t+N, greater<double>());

    double ans = 0;
    REP(i,0,dist.size()){
      ans += dist[i] / t[i];
    }
    printf("%.5lf\n", ans);

    //test
    /*
    REP(i,0,M) cout<<"d["<<i<<"] : "<<d[i].F<<endl;
    REP(i,0,M) cout<<"from["<<i<<"] : "<<from[i]<<endl;
    REP(i,0,dist.size()) cout<<dist[i]<<" ";
    cout<<endl;
    REP(i,0,N) cout<<t[i]<<" ";
    cout<<endl;
    REP(i,0,nodes.size()) cout<<nodes[i]<<" ";
    cout<<endl;
    */
  }



  return 0;
}
