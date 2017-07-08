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

int main(){
  int N;
  cin>>N;
  if(N==0){
    cout<<0<<endl;
    return 0;
  }
  string ans = "";
  while(N/7 != 0 || N%7 != 0){
    ans.insert(0,to_string(N%7));
    N /= 7;
  }
  cout<<ans<<endl;
  return 0;
}
