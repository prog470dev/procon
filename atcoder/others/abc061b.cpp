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
#define F first
#define S second

using namespace std;

int nums[55];

int main() {
  int N, M;
  cin>>N>>M;

  REP(i,0,M){
    int a, b;
    cin>>a>>b;
    nums[a-1]++;
    nums[b-1]++;
  }

  REP(i,0,N){
    cout<<nums[i]<<endl;
  }


  return 0;
}
