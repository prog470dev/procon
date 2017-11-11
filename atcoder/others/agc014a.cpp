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

long long A, B, C;

int main() {

  cin>>A>>B>>C;
  long long sa=A, sb=B, sc=C;
  long long cnt = 0;
  while(1){
    //cout<<sa<<" "<<sb<<" "<<sc<<endl;
    if(sa==A&&sb==B&&sc==C&&cnt!=0){
      cout<<-1<<endl;
      break;
    }
    if(sa%2==1||sb%2==1||sc%2==1){
      cout<<cnt<<endl;
      break;
    }
    long long ta = sa, tb = sb, tc = sc;
    sa = (tb+tc)/2; sb = (ta+tc)/2; sc = (ta+tb)/2;
    cnt++;
  }


  return 0;
}
