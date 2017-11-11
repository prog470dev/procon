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

  int A, B, C;
  cin>>A>>B>>C;

  int i = 1, j = 0;
  while(1){
    while(1){
      if(A*i < B*j){
        j = 0;
        break;
      }
      int tmp = A*i - B*j;
      if(tmp == C){
        cout<<"YES"<<endl;
        return 0;
      }
      if(tmp == 0){
        cout<<"NO"<<endl;
        return 0;
      }
      j++;
    }
    i++;
  }

  return 0;
}
