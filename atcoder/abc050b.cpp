#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {

  int N, T[105], M,P[105], X[105];
  long long sum = 0;
  cin>>N;
  for(int i=0; i<N; i++) cin>>T[i], sum += T[i];
  cin>>M;
  for(int i=0; i<M; i++) cin>>P[i]>>X[i];

  for(int i=0; i<M; i++){
    cout<<sum - T[P[i]-1] + X[i]<<endl;
  }

  return 0;
}
