/*
・現在の状態に、Ri*xを加えて、C以上のノードになったら、
　あとは水の量で自由に濃度を調整できる。
　→　C = (Ri+R*x)/Wi を解くだけ。
　※ただし、最初から濃度C以上なら、ルーは加えない。
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

int main() {
  int Ri,W,C,R;
  while(1){
    cin>>Ri>>W>>C>>R;
    if(Ri==0&&W==0&&C==0&&R==0) break;
    if(C*W <= Ri){
      cout<<0<<endl;
    }else{
      cout<<((C*W-Ri)+(R-1))/R<<endl;
    }
  }

  return 0;
}
