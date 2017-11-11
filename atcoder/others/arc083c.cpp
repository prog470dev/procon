/*
# 単純に全通り試すことが可能だったが、制約を見落として、無駄にDPを考えていた。
# 比はどうすれば式で比較できるか考える。（値そのものを出せなくても”比較”できればいい。）
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
#include <deque>
#include <algorithm>
#include <utility>

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long  LLINF = 1e18;

using namespace std;


/*==================================================*/

/*==================================================*/

int A, B, C, D, E, F;
int slt[6010];

double rate;
int ansslt;
int answtr;

void func(int na, int nb){
  for(int wa = na; wa*100 <= F; wa += A){
    for(int wb = nb; wb*100 <= F; wb += B){
      for(int sc = 0; sc <= F; sc += C){
        for(int sd = 0; sd <= F; sd += D){

          if(wa*100+wb*100+sc+sd > F) continue;
          if(sc+sd > (wa+wb)*E) continue;

          //if( ansslt*(wa*100+wb*100) <= answtr*(sc+sd)){
          if( ansslt*(wa*100+wb*100+sc+sd) <= (answtr+ansslt)*(sc+sd)){
            ansslt = sc+sd;
            answtr = wa*100+wb*100;
          }

          // if(rate < (double)(sc+sd)/(double)(sc+sd+wa*100+wb*100)){
          //   rate = (double)(sc+sd)/(double)(sc+sd+wa*100+wb*100);
          //   ansslt = sc+sd;
          //   answtr = wa*100+wb*100;
          // }
        }

      }
    }
  }
}

int main(){

  cin>>A>>B>>C>>D>>E>>F;

  // func(A,0);
  // func(0,B);
  func(0,0);
  cout<<ansslt+answtr<<" "<<ansslt<<endl;


  return 0;
}
