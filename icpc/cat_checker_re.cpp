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

string S;
/*  solution_1
int ind;
int state = 0;
bool parse(){
  if(ind == S.size()) return false;
  bool ret = true;
  if(S[ind] == 'm'){
    ind++;
    while(S[ind]!='w'){
      state = 1;
      bool tmp = parse();
      if(!tmp) return false;
    }
    ind++;
  }else if(state == 1 && S[ind] == 'e'){
    state = 2;
    ind++;
    ret = true;
  }else if(state == 2 && S[ind] == 'w'){
    state = 0;
    ind++;
    ret = true;
  }else{
    ret = false;
  }
  return ret;
}
*/

//solution_2
int parse(int p){
  if(S.size() <= p){
    return -1;
  }

  if(S[p] != 'm'){
    /*
    *パース対象の先頭は'm'である必要がある。
    *（pが進まずそうしなければ無限ループに入る）
    */
    return -1;
  }
  p++;
  if(S[p] != 'e'){
    p = parse(p);
    if(p==-1 || p >= S.size()) return -1;
  }
  p++;
  if(S[p] != 'w'){
    p = parse(p);
    if(p==-1 || p >= S.size()) return -1;
  }
  /*
  *ここでもインクリメントしないと
  *再帰呼び出しの位置に戻ったときに次の文字を読み込めない
  */
  p++;
  return p;
}

int main(){
  cin>>S;

  /*  solution_1
  ind = 0;
  if(parse() && ind == S.size()) cout<<"Cat"<<endl;
  else cout<<"Rabbit"<<endl;
  */

  //solution_2
  int t = parse(0);
  if(t == S.size()) cout<<"Cat"<<endl;
  else cout<<"Rabbit"<<endl;

  return 0;
}
