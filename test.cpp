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

#define REP(i,n,N) for(int i=n;i<(int)N;i++)
#define RREP(i,n,N) for(int i=N-1;i>=n;i--)
#define p(s) cout<<(s)<<endl;
#define CK(n,a,b) ((a)<=(n)&&(n)<=(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const int inf=1e9;

int N,M,K,s;
ll P,Q;
bool zon[100010];
int dang[100010];
vector< pair<ll,int> > edge[100010];
ll d[100010];

int main() {
	cin>>N>>M>>K>>s>>P>>Q;
	REP(i,0,N) dang[i] = inf;
	REP(i,0,K){
		int t;
		cin>>t;
		zon[t-1] = true;
	}
	REP(i,0,M){
		int a,b;
		cin>>a>>b;
		if(b!=N) edge[a-1].push_back(make_pair(P, b-1));
    else edge[a-1].push_back(make_pair(0LL, b-1));
    if(a!=N) edge[b-1].push_back(make_pair(P, a-1));
    else edge[b-1].push_back(make_pair(0LL, a-1));
    /*N-1ノードは０にする*/
	}

	REP(i,0,N){
		if(zon[i] == false) continue;
		//bfs
		queue<pair<int,int> > q;
		bool visited[100010];
		REP(j,0,N) visited[j] = false;
		q.push(make_pair(0,i));
		while(!q.empty()){
			int curNode = q.front().S;
			int curStep = q.front().F;
			q.pop();
			if(curStep > s) continue;
			if(dang[curNode] <= curStep) continue;
			dang[curNode] = curStep;
			visited[curNode] = true;
			REP(j,0,edge[curNode].size()){
				if(visited[edge[curNode][j].S]) continue;
				q.push(make_pair(curStep+1,edge[curNode][j].S));
			}
		}
	}

/*
	REP(i,0,N){
		if(dang[i] == inf) continue;
		REP(j,0,edge[i].size()){
      int fromNode = edge[i][j].S;
			edge[fromNode][i].F = Q;
      if(fromNode==0)cout<<fromNode<<","<<i<<" = "<<Q<<endl;
			//cout<<fromNode+1<<" -> "<<i+1<<" "<<edge[fromNode][i].F<<endl;
		}
	}
*/
  /*修正箇所*/
  REP(i,0,N){
    REP(j,0,edge[i].size()){
      int toNode = edge[i][j].S;
      if(dang[toNode] != inf && toNode != N-1){
          edge[i][j].F = Q;
      }
    }
  }

	//ダイクストラ
	REP(i,0,N) d[i] = LONG_LONG_MAX;
	priority_queue<pair<ll,int> > PQ;
	PQ.push(make_pair(0LL,0));
	while(!PQ.empty()){
		ll curCost = -PQ.top().F;
		int curNode = PQ.top().S;
		PQ.pop();
		if(d[curNode] <= curCost) continue;
		d[curNode] = curCost;
		//cout<<"curNode: "<<curNode+1<<" (cost:"<<d[curNode]<<")"<<endl;
		REP(i,0,edge[curNode].size()){
			int nextNode = edge[curNode][i].S;
      ll edgeCost = edge[curNode][i].F;
			if(zon[nextNode]) continue;
			PQ.push(make_pair(-(curCost+edgeCost),nextNode));
		}
	}

	cout<<d[N-1]<<endl;

	return 0;
}
