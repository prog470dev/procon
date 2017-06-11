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

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

string S, SP;
int N;

int main() {
  cin>>N;
  cin>>S;
  int l = 0, r = S.size();
  int cnt = 0, sz = S.size();
  REP(i,0,sz){
    if(S[i] == '('){
      //l = i;
      cnt++;
      //cout<<"l pos : "<<l<<endl;
    }else{
      cnt--;
    }

    if(cnt < 0){
      S = S.substr(0,l) + "(" + S.substr(l,(sz-l));
      sz++;
      i++;
      cnt = 0;
    }
  }

  if(cnt > 0){
    REP(i,0,cnt) S += ")";
  }

  cout<<S<<endl;

  return 0;
}
