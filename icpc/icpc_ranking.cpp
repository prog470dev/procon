/*
2017_05_14_AC
<point>
・vectorの複数あるソート基準について、正負を調整すれば、
　意図どおりの順番で並べることができる。
　（取り出すときに-1のかけ忘れに注意！）
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

int M,T,P,R,m,t,p,j;
int pen[55][15];

int main() {
  while(1){
      cin>>M>>T>>P>>R;
      if(M==0) break;
      REP(i,0,T)REP(k,0,P) pen[i][k]=0;
      vector< pair<pair<int,int>,int> > v(T); //<solv, pen>, id
      REP(i,0,T) v[i].F.F = v[i].F.S = 0, v[i].S = (-1)*i;
      REP(i,0,R){
        cin>>m>>t>>p>>j;
        if(j==0){
            v[t-1].F.F++;
            v[t-1].F.S += m + pen[t-1][p-1]*20;
        }
        else pen[t-1][p-1]++;
      }
      sort(v.begin(),v.end());

      bool flag = true;
      for(int sol=P; 0<=sol; sol--){
        REP(i,0,v.size()){
          if(v[i].F.F==sol){
            if(flag){
              cout<<(-1)*v[i].S+1;
              flag = false;
            }else{
              if(i>0){
                if(v[i].F.S==v[i-1].F.S && v[i].F.F==v[i-1].F.F) cout<<"="<<(-1)*v[i].S+1;
                else cout<<","<<(-1)*v[i].S+1;
              }else{
                cout<<","<<(-1)*v[i].S+1;
              }
            }
          }
        }
      }
      cout<<endl;
  }


  return 0;
}
