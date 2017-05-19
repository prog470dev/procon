/*
2017_03_15_AC
＜ポイント＞
・charをstringに変換するテクニック： sc = string() + c;
・Kがいくつでも、調べるときに使う文字列は同じだから、先にコードを作っておく。
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
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int main() {

  while(1){
    int n;
    cin>>n;
    if(n == 0) break;
    string s[50];
    REP(i,0,n){
      cin>>s[i];
    }
    string ns[50];
    REP(i,0,n){
      ns[i] = "";
      REP(j,0,s[i].size()){
        string c;
        if(j == 0||s[i][j-1]=='a'||s[i][j-1]=='i'||s[i][j-1]=='u'||s[i][j-1]=='e'||s[i][j-1]=='o'){
          c = string() + s[i][j];
        }else{
          c = "";
        }
        ns[i] += c;
      }
    }
    int k = 1;
    bool flag;
    while(k <= 50){
      set<string> se;
      flag = true;
      REP(i,0,n){
        string ts;
        if(ns[i].size() > k) ts = ns[i].substr(0,k);
        else ts = ns[i];
        if(se.find(ts) != se.end()){
          flag = false;
          break;
        }
        se.insert(ts);
      }
      if(flag){
        cout<<k<<endl;
        break;
      }
      k++;
    }
    if(!flag) cout<<-1<<endl;

  }

  return 0;
}
