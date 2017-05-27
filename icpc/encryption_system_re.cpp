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
#define ll long long;

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

string s;
bool flag[26];
vector<string> v;

void dfs(int pos, string str){
  if(pos == s.size()){
    v.push_back(str);
    return;
  }
  if(flag[s[pos]-'a'] || s[pos] == 'a'){
    bool tmp = flag[s[pos]-'a'];
    flag[s[pos]-'a'] = true;
    dfs(pos+1, str + s[pos]);
    flag[s[pos]-'a'] = tmp;
  }
  if(!flag[s[pos]+1-'a'] && s[pos]!='z'){
    flag[s[pos]+1-'a'] = true;
    dfs(pos+1, str + (char)(s[pos]+1));
    flag[s[pos]+1-'a'] = false;
  }
  return;
}

int main() {
  while (1) {
      cin>>s;
      if(s == "#") break;
      REP(i,0,26) flag[i] = false;
      v.clear();
      dfs(0,"");
      cout<<v.size()<<endl;
      if(v.size() <= 10){
        REP(i,0,v.size()) cout<<v[i]<<endl;
      }else{
        REP(i,0,5) cout<<v[i]<<endl;
        REP(i,v.size()-5,v.size()) cout<<v[i]<<endl;
      }
  }
  return 0;
}
