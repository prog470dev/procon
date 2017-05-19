/*
2017_05_08_AC
<point>
・左端の"ABC"は"A"に、右端は"C"に、それ以外は"B"に変換する。
・変換前と変換後で、変換した文字の文字数が違うと、可逆変換でなくなる。
<caution>
・左端や右端に"ABC"があった場合の処理は、変換する文字の指定までで、変換そのものはしない。
　（変換処理は最後にまとめてやる。）
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

int main() {
  cin>>S;
  while(1){
    //cout<<"S: "<<S<<endl;
    if(S=="ABC"){
      cout<<"Yes"<<endl;
      return 0;
    }
    if(S.size() < 5) break;
    int i = 1;
    if(S.substr(0,3)=="ABC") i=0;
    else if(S.substr(S.size()-3,3)=="ABC") i=2;
    int cnt = 0;
    REP(pos,0,S.size()-2){
      if(S.substr(pos,3)=="ABC"){
        S.replace(pos,3,x[i]);
        cnt++;
      }
    }
    /*変換できない or 変換前と後で変換した文字数が異なる（不可逆）*/
    if(cnt==0 || cnt!=count(S.begin(),S.end(),cx[i])) break;
  }
  cout<<"No"<<endl;

  return 0;
}
