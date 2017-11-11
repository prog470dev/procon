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

  int W, a, b;
  cin>>W>>a>>b;

  if(a + W < b){
    cout<<b - (a+W)<<endl;
  }else if(b + W < a){
    cout<<a - (b+W)<<endl;
  }else{
    cout<<0<<endl;
  }

  return 0;
}
