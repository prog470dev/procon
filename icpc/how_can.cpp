/*
<point>
・左括弧 "(" が来るたびに、pair<演算子,<第一項,第二項>> p を生成し、
　それぞれ３つの項に対してparse()後、計算して値を返す。
・インデックスは、グローバルにしないと、進まなくなる。
・左括弧 ")" を無視するための分岐をパースの中に作っておく。
<caution>
・"index"は予約語らしいので、変数名としては使わない。
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

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

string s;
int state[3], ind;

int parse(){
  while(s[ind]==')') ind++;
  if(s[ind]=='0'||s[ind]=='1'||s[ind]=='2'){
    return (int)(s[ind]-'0');
  }
  if(s[ind]=='P'||s[ind]=='Q'||s[ind]=='R'){
    return state[s[ind]-'P'];
  }
  if(s[ind]=='*') return 1;
  if(s[ind]=='+') return 2;

  if(s[ind]=='-'){
    pair< int, pair<int,int> > p;
    ind++;
    p.second.first = parse();
    p.first = 0;
    if(p.second.first == 0) return 2;
    if(p.second.first == 1) return 1;
    if(p.second.first == 2) return 0;
  }
  if(s[ind]=='('){
    pair< int, pair<int,int> > p;
    ind++;
    p.second.first = parse();
    ind++;
    p.first = parse();
    ind++;
    p.second.second = parse();
    if(p.first == 1){
      if(p.second.first==0 || p.second.second==0) return 0;
      else if(p.second.first==2 && p.second.second==2) return 2;
      else return 1;
    }else if(p.first == 2){
      if(p.second.first==2 || p.second.second==2) return 2;
      else if(p.second.first==0 && p.second.second==0) return 0;
      else return 1;
    }
  }
  return -999999;
}

int main() {
  while(1){
    cin>>s;
    if(s==".") break;
    int cnt = 0;
    /*(0,0,0)~(1,1,1)*/
    REP(pi,0,3){
      REP(qi,0,3){
        REP(ri,0,3){
          state[0]=pi; state[1]=qi; state[2]=ri;
          ind = 0;
          if(parse() == 2) cnt++;
        }
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}
