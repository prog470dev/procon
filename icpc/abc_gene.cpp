/*
2017_05_04
・バグが取れない・・・
・文字列処理についての便利なメソッドを調べる。
（find, erase など）
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

string S;
string x[] = {"A","B","C"};
char cx[] = {'A','B','C'};
bool ans = false;

int main() {
  cin>>S;
  stack<string> stk;
  stk.push(S);
  while(!stk.empty()){
    string TS = stk.top(); stk.pop();
    //cout<<TS<<endl;
    if(TS == "ABC"){
      ans = true;
      break;
    }
    //"ABC"の位置を記録
    int pos = 1;
    vector<int> v;//ABCのBｎ位置
    bool flag = false;//ABCがあるか？;
    while(pos < TS.size()-1){
    if(TS[pos-1]=='A'&&TS[pos]=='B'&&TS[pos+1]=='C'){
        v.push_back(pos);
        flag = true;
        pos += 2;
      }else{
        pos++;
      }
    }
    //チェック
    if(!flag) continue;
    REP(i,0,3){
      //文字列変換
      string ts = "";
      int p = 0;
      REP(j,0,v.size()){
        int diff = (v[j] - 1) - p;
        ts += TS.substr(p, diff) + x[i];
        p = v[j]+2;
      }
      ts += TS.substr(p, TS.size()-p);
      if(count(ts.begin(),ts.end(),cx[i]) == count(TS.begin(),TS.end(),cx[i])) stk.push(ts);
    }
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}
