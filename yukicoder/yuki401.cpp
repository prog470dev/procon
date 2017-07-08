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

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int N, num=1, cnt=0;
int d[35][35];

int main(){
  cin>>N;
  int k = 0;
  int range=N-1;
  int posy = 0, posx = 0;
  d[posy][posx] = 1;
  while(1){
    REP(i,0,range){
      num++;
      posy += dy[k];
      posx += dx[k];
      d[posy][posx] = num;
    }
    k = (k+1)%4;
    if(range != N-1) cnt++;
    if(num == N*N) break;
    if(range != N-1 && cnt%2==0){
      range--;
    }else if(range == N-1 && num == 3*N-2){
      range--;
    }
  }

  REP(i,0,N){
    REP(j,0,N){
      printf("%03d ", d[i][j]);
    }
    cout<<endl;
  }

  return 0;
}
