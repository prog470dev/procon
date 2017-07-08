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
#include <deque>
#include <algorithm>

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

int main(){
  int N, K;
  cin>>N>>K;
  if(K ==0 || N < K){
    cout<<0<<endl;
  }else if(N%2==1 && K == (N+1)/2){
    cout<<N-1<<endl;
  }else{
    cout<<N-2<<endl;
  }

  return 0;
}
