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

vector< pair<int, char> > v;
int ind = 0;

int calc(int level){
  if(isdigit(v[ind].second)) {
    return (v[ind].second - '0');
  }
  vector<int> tv;
  char op = v[ind].second;
  while(ind < v.size()-1){
    ind++;
    if(v[ind].first == level+1){
      tv.push_back(calc(level+1));
    }else{
      ind--;
      break;
    }
  }
  int ret;
  if(op == '*') ret = 1;
  else ret = 0;
  REP(i,0,tv.size()){
    if(op == '*') ret *= tv[i];
    else ret += tv[i];
  }
  return ret;
}

int main() {
  while(1){
    int n;
    cin>>n;
    if(n == 0) break;
    string s;
    v.erase(v.begin(), v.end());
    REP(i,0,n){
      cin>>s;
      int tmp = 0;
      char c;
      REP(j,0,s.size()){
        if(s[j] == '.') tmp++;
        if(j == (s.size()-1)) c = s[j];
      }
      v.push_back(make_pair(tmp, c));
    }
    ind = 0;
    cout<<calc(0)<<endl;
  }

  return 0;
}
