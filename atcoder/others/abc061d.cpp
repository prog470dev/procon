/*
2017_05_13_AC
<point>
・経路のコストが最大化するようにWFする。（いつもと逆）
（？）・ノード[N-1]が、自分自身への”正の”経路を持っている場合は、
　無限にコストを増やすことが可能になる。
　※N-1からN-1への初期値は-1。
・計算時間は、ピッタリ10^9なのでギリギリ通る。
<caution>
★多分、嘘解法！！
（コーナーケース）
3 4
1 2 4
2 3 3
1 3 5
2 1 2
※1と２で無限ループできる。
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

const long long INF = 1e18;

int N,M;
long long road[1010][1010];

int main() {
  cin>>N>>M;

  REP(i,0,N){
    REP(j,0,N){
      if(i==j) road[i][j] = 0;
      else road[i][j] = (-1)*INF;
    }
  }

  REP(i,0,M){
    int a, b, c;
    cin>>a>>b>>c;
    road[a-1][b-1] = c;
  }

  REP(k,0,N){
    REP(i,0,N){
      REP(j,0,N){
        road[i][j] = max(road[i][j],road[i][k] + road[k][j]);
      }
    }
  }

  bool flag = false;
  REP(i,0,N) if(road[i][i]>0 && road[0][i]!=(-1)*INF) flag = true;

  if(road[N-1][N-1] > 0){
  //if(flag){
    cout<<"inf"<<endl;
  }else{
    cout<<road[0][N-1]<<endl;
  }

  return 0;
}
