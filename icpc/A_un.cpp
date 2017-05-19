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
int N;
string s[105];
int main() {
  cin>>N;
  REP(i,0,N)cin>>s[i];
  int a=0, u=0;
  REP(i,0,N){
    if(s[i]=="A") a++;
    else{
      u++;
      if(a < u){
        cout<<"NO"<<endl;
        return 0;
      }
    }
  }
  if(a < u || a!=u){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
  }
  return 0;
}
