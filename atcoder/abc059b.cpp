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

  string A, B;
  cin>>A>>B;

  if(A.size() > B.size()){
    cout<<"GREATER"<<endl;
    return 0;
  }else {
    if(A.size() == B.size()){
      REP(i,0,A.size()){
        if(A[i] > B[i]){
          cout<<"GREATER"<<endl;
          return 0;
        }
        if(A[i] < B[i]){
          cout<<"LESS"<<endl;
          return 0;
        }
      }
      cout<<"EQUAL"<<endl;
    }else{
      cout<<"LESS"<<endl;
      return 0;
    }
  }

  return 0;
}
