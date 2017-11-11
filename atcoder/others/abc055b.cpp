#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;

int main() {

  int N;
  cin>>N;

  long long ans = 1;
  for(int i=1; i<=N; i++){
    ans = (ans * i) % MOD;
  }

  cout<<ans<<endl;

  return 0;
}
