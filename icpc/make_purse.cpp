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

const int INF = 1e9;
int coins[4] = {10,50,100,500};
bool flag = false;

int main() {
  int price,c[4];
  while(1){
    cin>>price;
    if(price==0) break;
    REP(i,0,4)cin>>c[i];
    int ans[4] = {}, m = INF;
    REP(i,0,c[0]+1){
      REP(j,0,c[1]+1){
        REP(k,0,c[2]+1){
          REP(l,0,c[3]+1){
            int pay = 10*i+50*j+100*k+500*l;
            if(price > pay) continue;
            int ex[4] = {};
            pay -= price;
            for(int ii=3; 0<=ii; ii--){
              if(pay >= coins[ii]){
                ex[ii] = pay/coins[ii];
                pay = pay%coins[ii];
              }
            }
            if((i!=0&&ex[0]!=0)||(j!=0&&ex[1]!=0)||(k!=0&&ex[2]!=0)||(l!=0&&ex[3]!=0)) continue;
            if(m > (c[0]+c[1]+c[2]+c[3])+(-1)*(i+j+k+l)+(ex[0]+ex[1]+ex[2]+ex[3])){
              m = (c[0]+c[1]+c[2]+c[3])+(-1)*(i+j+k+l)+(ex[0]+ex[1]+ex[2]+ex[3]);
              ans[0]=i; ans[1]=j; ans[2]=k; ans[3]=l;
            }
          }
        }
      }
    }
    if(flag)cout<<endl;
    flag = true;
    REP(i,0,4){
      if(ans[i]!=0) cout<<coins[i]<<" "<<ans[i]<<endl;
    }
  }

  return 0;
}
