/*
2017_03_14_AC
＜疑問＞
・最大何回まで繰り返せば良い？なんで今回の回数でACしてしまったのか？
 =>同じ位置に戻ってきたらアウト（(a+b)の整数倍が60の倍数のとき）
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
  int a, b, c;
  cin>>a>>b>>c;
  if((a + b) % 60 == 0 && a < c){
    cout<<-1<<endl;
    return 0;
  }

  for(int i=0; ;i++){
    if((a + b)*i % 60 <= c && c <= (a + b)*i % 60 + a){
        cout<<c + 60*((a+b)*i/60)<<endl;
        return 0;
    }
    if(i > 0 && (a + b)*i % 60== 0){
      cout<<-1<<endl;
      return 0;
    }
  }

  return 0;
}
