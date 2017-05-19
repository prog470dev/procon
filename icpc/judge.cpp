/*
2017_05_13_AC
<point>
・(AC数,ペナルティ,チームNo)を、<降順,昇順,昇順>でソートしたい。
　→まず普通にソート<昇順,昇順,昇順>を実行する。
　→毎回AC数を決め打ちで大きい方から固定で、vectorを上から見ていって、
　 固定したAC数を持つ要素だけを、出力する。
　（解決策）AC数に負を書けて記憶しておく。
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

using namespace std;

int T,P,R,tID,pID,tim;
string message;
int solv[55],pen[55], wap[55][505];

int main() {
  while(1){
    cin>>T>>P>>R;
    if(T==0&&P==0&&R==0) break;
    vector< pair<pair<int,int>,int> > v(T); //score,pen,tid
    REP(i,0,T){
      v[i].first.first = v[i].first.second = 0;
      v[i].second = i;
      REP(j,0,P) wap[i][j]=0;
    }
    REP(i,0,R){
      cin>>tID>>pID>>tim>>message;
      if(message=="CORRECT"){
        v[tID-1].first.first++;
        v[tID-1].first.second += wap[tID-1][pID-1]*1200+tim;
      }else{
        wap[tID-1][pID-1]++;
      }
    }
    sort(v.begin(),v.end());
    for(int score=P; 0<=score; score--){
      REP(i,0,v.size()){
        if(v[i].first.first==score) cout<<v[i].second+1<<" "<<v[i].first.first<<" "<<v[i].first.second<<endl;
      }
    }
  }

  return 0;
}
