/*
2017_06_04_AC
<point>
・ノーマルな四則演算パーサーに優先度をつけた。
　（もっと完結にはできるはず → 濱屋さんにGO）
<caution>
・整数の最大値（最小値）を取得刷る方法。※一ずれているので"-"をつけるだけでは駄目。
  ll ans = numeric_limits<long long>::min();
  ll ans = numeric_limits<long long>::max();
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
#define F first
#define S second
#define ll long long

const int INF = (1<<30);
const ll LLINF = (1LL<<62);

using namespace std;

typedef string::const_iterator State;

vector<char> ope[3];
vector<int> v;
int first, second, third;

ll firstParse(State &);
ll secondParse(State &);
ll thirdParse(State &);
ll number(State &);
ll factor(State &);

// 数字の列をパースして、その数を返す。
ll number(State &begin) {
  ll ret = 0;
  while (isdigit(*begin)) {
      ret = ret*10 + (*begin - '0');
      begin++;
  }
  return ret;
}

// 括弧か数をパースして、その評価結果を返す。
ll factor(State &begin) {
  if (*begin == '(') {
    begin++; // '('を飛ばす。
    ll ret;
    if(v.size()==3) ret = thirdParse(begin);
    else if(v.size()==2) ret = secondParse(begin);
    else if(v.size()==1) ret = firstParse(begin);
    begin++; // ')'を飛ばす。
    return ret;
  } else {
      return number(begin);
  }
  return -1;
}

//第一優先expression
ll firstParse(State &begin){
  ll ret = factor(begin);
  for (;;) {
    bool flag = false;
    REP(i,0,ope[first].size()){
      if (*begin == ope[first][i]) {
        flag = true;
        begin++;
        if(ope[first][i]=='+') ret += factor(begin);
        else if(ope[first][i]=='-') ret -= factor(begin);
        else if(ope[first][i]=='*') ret *= factor(begin);
        break;
      }
    }
    if(!flag) break;
  }
  return ret;
}

//第二優先expression
ll secondParse(State &begin) {
  ll ret = firstParse(begin);
  for (;;) {
    bool flag = false;
    REP(i,0,ope[second].size()){
      if (*begin == ope[second][i]) {
          flag = true;
          begin++;
          if(ope[second][i]=='+') ret += firstParse(begin);
          else if(ope[second][i]=='-') ret -= firstParse(begin);
          else if(ope[second][i]=='*') ret *= firstParse(begin);
          break;
      }
    }
    if(!flag) break;
  }
  return ret;
}

//第三優先expression
ll thirdParse(State &begin) {
  ll ret = secondParse(begin);
  for (;;) {
    bool flag = false;
    REP(i,0,ope[third].size()){
      if (*begin == ope[third][i]) {
          flag = true;
          begin++;
          if(ope[third][i]=='+') ret += secondParse(begin);
          else if(ope[third][i]=='-') ret -= secondParse(begin);
          else if(ope[third][i]=='*') ret *= secondParse(begin);
          break;
      }
    }
    if(!flag) break;
  }
  return ret;
}

int main() {
  string s;
  cin>>s;
  State start = s.begin();
  ll ans = numeric_limits<long long>::min();
  /*数字が小さほど優先度の高い演算子*/
  REP(i,0,3){
    REP(j,0,3){
      REP(k,0,3){

        REP(l,0,3) ope[l].clear();
        ope[i].push_back('+');
        ope[j].push_back('-');
        ope[k].push_back('*');

        v.clear();
        v.push_back(i);
        v.push_back(j);
        v.push_back(k);
        sort(v.begin(),v.end());
        //要素をユニークにして、優先度の「数」に調整
        v.erase(unique(v.begin(),v.end()),v.end());

        ll tmp;
        State start = s.begin();

        //使用する演算子の優先度の「数」で場合分け
        //（数が少ないほど、低レベルから呼び出す。）
        if(v.size() == 3){
          first = v[0]; second = v[1]; third = v[2];
          tmp = thirdParse(start);
        }else if(v.size() == 2){
          first = v[0]; second = v[1];
          tmp = secondParse(start);
        }else{
          first = v[0];
          tmp = firstParse(start);
        }
        ans = max(ans, tmp);

      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
