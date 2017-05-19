/*
2017_03_12_AC
・やるだけ。
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
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int main() {

  while(1){
    int n;
    cin>>n;
    if(n == 0) break;
    string s;
    int nums[40];
    REP(i,0,n){
      cin>>s;
      nums[i] = (int)s.size();
    }
    REP(i,0,n){
      int p = 0;
      int ch[5] = {};
      bool flag = false;
      REP(j,i,n){
        ch[p] += nums[j];
        if((p==0 || p==2) && ch[p]==5){
          p++;
        }else if((p==1 || p==3 || p==4) && ch[p]==7){
          p++;
        }
        if(p==5){
          cout<<i+1<<endl;
          flag = true;
          break;
        }
      }
      if(flag) break;
    }

  }

  return 0;
}
