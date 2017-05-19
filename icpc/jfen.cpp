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

int n, a, b, c, d;
string s;

int main() {

  while(1){
    cin>>s;
    if(s == "#") break;
    cin>>a>>b>>c>>d;

    string array[10];
    int cnt = 0, pos = 0;
    REP(i,0,s.size()){
      if(isdigit(s[i])){
        REP(j,0,(s[i]-'0')){
          array[cnt] += ".";
        }
      }else if(s[i] == 'b'){
        array[cnt] += "b";
      }else if(s[i] == '/'){
        cnt++;
      }
    }
    /////////////
    array[a-1][b-1] = '.';
    array[c-1][d-1] = 'b';
    /////////////
    string ans = "";
    REP(i,0,cnt+1){
      int tmp = 0;
      REP(j,0,array[i].size()){
        bool flag = true;
        if(array[i][j] == 'b'){
          if(tmp > 0){
            ans += to_string(tmp);
            tmp = 0;
          }
          flag = false;
          ans += "b";
        }else if(array[i][j] == '.'){
          tmp++;
        }
        if(j == array[i].size()-1){
          if(flag){
            ans += to_string(tmp);
            tmp = 0;
          }
          if(i != cnt) ans += "/";
        }
      }
    }

    cout<<ans<<endl;

}

  return 0;
}
