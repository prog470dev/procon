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

  char a, b;
  cin>>a>>b;

  if(a == 'H'){
    if(b == 'H'){
      cout<<"H"<<endl;
    }else{
      cout<<"D"<<endl;
    }
  }else{
    if(b == 'H'){
      cout<<"D"<<endl;
    }else{
      cout<<"H"<<endl;
    }
  }

  return 0;
}
