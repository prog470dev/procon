/*
・文字列変換系。
・どうしても上手く作れなかったら、更新する文字列とポインタはグローバルに設定。
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

string S;
string ans;
int p=0;
void parse(int cnt){
  if(p==S.size()) return;
  if(S[p] == '['){
    p++;
    int l = ans.size();
    parse(cnt);
    reverse(ans.begin()+l,ans.begin()+ans.size());
    p++;
    parse(cnt);
  }else if(S[p]==']'){
    return;
  }else if('A' <= S[p] && S[p] <= 'Z'){
    ans += 'A' + ((S[p]-'A'+cnt+2600000)%26);
    cnt = 0;
    p++;
    parse(cnt);
  }else if(S[p] == '?'){
    ans += 'A';
    cnt = 0;
    p++;
    parse(cnt);
  }else if(S[p] == '+'){
    cnt++;
    p++;
    parse(cnt);
  }else if(S[p] == '-'){
    cnt--;
    p++;
    parse(cnt);
  }
  return;
}

int main(){
  while(1){
    cin>>S;
    if(S==".") break;
    ans = "";
    p=0;
    parse(0);
    cout<<ans<<endl;
  }
  return 0;
}
