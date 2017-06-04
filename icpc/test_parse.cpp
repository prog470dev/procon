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

typedef string::const_iterator State;

int number(State &);
int factor(State &);
int term(State &);
int expression(State &);

// 数字の列をパースして、その数を返す。
int number(State &begin) {
  int ret = 0;
  while (isdigit(*begin)) {
    ret *= 10;
    ret += *begin - '0';
    begin++;
  }
  return ret;
}

// 括弧か数をパースして、その評価結果を返す。
int factor(State &begin) {
    if (*begin == '(') {
        begin++; // '('を飛ばす。
        int ret = expression(begin);
        begin++; // ')'を飛ばす。
        return ret;
    } else {
        return number(begin);
    }
    //エラー対策
    return -INF;
}

// 乗算除算の式をパースして、その評価結果を返す。
int term(State &begin) {
  int ret = factor(begin);
  for (;;) {
    if (*begin == '*') {
        begin++;
        ret *= factor(begin);
    } else if (*begin == '/') {
        begin++;
        ret /= factor(begin);
    } else {
        break;
    }
  }
  return ret;
}

// 四則演算の式をパースして、その評価結果を返す。
int expression(State &begin) {
  int ret = term(begin);
  for (;;) {
    if (*begin == '+') {
        begin++;
        ret += term(begin);
    } else if (*begin == '-') {
        begin++;
        ret -= term(begin);
    } else {
        break;
    }
  }
  return ret;
}


int main() {
    string S;
    cin>>S;
    State state = S.begin();
    cout<<expression(state)<<endl;
  
  return 0;
}
