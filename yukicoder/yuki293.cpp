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
const long long  LLINF = 1e18;

using namespace std;

string A,B;

int main(){
  cin>>A>>B;
  if(A.size() == B.size()){
    REP(i,0,A.size()){
      if(A[i]==B[i]) continue;
      if((A[i]=='4'&&B[i]=='7')){
        cout<<A<<endl;
      }else if((A[i]=='7'&&B[i]=='4')){
        cout<<B<<endl;
      }else{
        cout<<((A[i]>B[i])?A:B)<<endl;
      }
      break;
    }
  }else{
    cout<<((A.size()>B.size())?A:B)<<endl;
  }
  return 0;
}
