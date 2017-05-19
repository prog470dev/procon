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

  long long N;
  cin>>N;

  int ans = 1;
  long long num = 3;
  while(1){
    if(N <= num) break;
    num  *= 3;
    ans++;
  }

  cout<<ans<<endl;

  return 0;
}
