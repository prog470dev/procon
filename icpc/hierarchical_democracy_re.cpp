/*
・「囲む」ための左端トークンに出会うたびに、
 　新しいオブジェクトを生成し、そこでいちからスタート。
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

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

int N;
string S;

int ind;
int parse(){
  int ret = 0;
  if(S[ind] == '['){
    vector<int> v;
    ind++;
    while(S[ind]!=']') v.push_back(parse());
    ind++;
    sort(v.begin(),v.end());
    REP(i,0,v.size()/2+1) ret += v[i];
  }else if(isdigit(S[ind])){
    while(isdigit(S[ind])){
      ret = 10*ret + (int)(S[ind] - '0');
      ind++;
    }
    ret = ret/2 + 1;
  }
  return ret;
}

int main(){
  cin>>N;
  REP(i,0,N){
    cin>>S;
    ind=0;
    cout<<parse()<<endl;
  }
  return 0;
}
