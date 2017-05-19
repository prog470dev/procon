#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int INF = 1000000000;

int main() {

  int N, M, a, b, c;
  cin>>N>>M;
  int v[105][105];
  for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         v[i][j] = INF;
      }
  }
  for(int i=0; i<M; i++){
    cin>>a>>b>>c;
    v[a-1][b-1] = c;
    v[b-1][a-1] = c;
  }

  set< pair<int, int> > s;

  for(int i=0; i<N; i++){
    int dist[105];
    bool visit[105];
    fill(dist, dist+N, INF);
    fill(visit, visit+N, false);
    dist[i] = 0;
    while(1){
      int u = -1, d = INF;
      for(int k=0; k<N; k++){
        if(!visit[k] && dist[k] < d){
          u = k;
          d = dist[k];
        }
      }
      if(u == -1) break;
      visit[u] = true;
      for(int j=0; j<N; j++){
        if(v[u][j] != 0){
          dist[j] = min(dist[j], dist[u]+v[u][j]);
        }
      }
    }

    //cout<<"i:"<<i<<endl;
    for(int l=0; l<N; l++){
      for(int r=0; r<N; r++){
        if(dist[l] - v[l][r] == dist[r] || dist[r] - v[l][r] == dist[l]){
          int a = l, b = r;
          if(a > b){
            swap(a, b);
          }
          //cout<<"a:"<<a<<" b:"<<b<<endl;
          s.insert(make_pair(a,b));
        }
      }
    }

  }

  cout<<M - (int)s.size()<<endl;

  //cout<<"s.size(): "<<s.size()<<endl;

  return 0;
}
