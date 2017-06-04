/*
2017_06_04_AC
<point>
・'?'は無条件で'A'に変換して構わない。
<caution>
・式の最初から'?'が出て来るケースを見落としていた。
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

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

int ind;
string S;

string dfs(){
  string ret = "";
  char c = S[ind];
  if(c == '['){
    ind++;
    string rev = dfs();
    ind++;
    reverse(rev.begin(), rev.end());
    ret += rev;
    ret += dfs();
  }else if(('A'<=S[ind] && S[ind]<='A'+26) || S[ind]=='?'){
    char ac;
    if(S[ind]=='?') ac = 'A';
    else ac = S[ind];
    ret += ac;
    ind++;
    ret += dfs();
  }else if(S[ind] == '+' || S[ind] == '-'){
    int cnt = 0;
    while(S[ind] == '+' || S[ind] == '-'){
      if(S[ind] == '+') cnt++;
      else cnt--;
      ind++;
    }
    if(S[ind]=='?') ret += 'A';
    else ret += 'A' + (S[ind]-'A'+cnt+2600)%26;
    ind++;
    ret += dfs();
  }
  return ret;
}

int main() {
  while(1){
    cin>>S;
    if(S==".") break;
    ind = 0;
    cout<<dfs()<<endl;
  }
  return 0;
}
