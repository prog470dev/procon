/*
2017_05_28_AC
<point>
・森において、「木の数」＝「ノードの数」ー「辺の数」
<caution>
・縦の記録：対象の行「より上」の情報
・横の記録：対象の行「より左」の情報
 → 辺に関する情報は、縦と横は別に記録する。
　（範囲で切るときに切り方を変える必要がある。）
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

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long;

using namespace std;

const int INF = 1e9;

int N, M, Q;
string S[2005];
int node[2005][2005], edgeH[2005][2005],edgeW[2005][2005];

int main() {
  cin>>N>>M>>Q;
  REP(i,0,N) cin>>S[i];

  /*累積和の配列は、一個ずつずらす（範囲外アクセス対策）*/
  REP(i,0,N){
    REP(j,0,M){
      if(S[i][j] == '1') node[i+1][j+1]++;
      if(j > 0){
        if(S[i][j-1] == '1' && S[i][j] == '1') edgeW[i+1][j+1]++;
      }
      if(i > 0){
        if(S[i-1][j] == '1' && S[i][j] == '1') edgeH[i+1][j+1]++;
      }
    }
  }

  REP(i,0,N+1){
    REP(j,1,M+1){
      node[i][j] += node[i][j-1];
      edgeW[i][j] += edgeW[i][j-1];
      edgeH[i][j] += edgeH[i][j-1];
    }
  }
  REP(i,1,N+1){
    REP(j,0,M+1){
      node[i][j] += node[i-1][j];
      edgeW[i][j] += edgeW[i-1][j];
      edgeH[i][j] += edgeH[i-1][j];
    }
  }

  REP(i,0,Q){
    int y1,x1,y2,x2;
    cin>>y1>>x1>>y2>>x2;

    int n,eh,ew;
    n = node[y2][x2] - node[y2][x1-1] - node[y1-1][x2] + node[y1-1][x1-1];
    //縦の記録：対象行より「上」の情報　→　y1につての情報は消すべき(範囲より上の辺を切る)
    eh = edgeH[y2][x2] - edgeH[y2][x1-1] - edgeH[y1][x2] + edgeH[y1][x1-1];
    ew = edgeW[y2][x2] - edgeW[y2][x1] - edgeW[y1-1][x2] + edgeW[y1-1][x1];

    cout<<n-eh-ew<<endl;
  }

  return 0;
}
