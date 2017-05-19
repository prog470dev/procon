#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {

  int K, S;
  cin>>K>>S;

  long long ans = 0;
  for(int i = 0; i<=K; i++){
    for(int j = 0; j<=K; j++){
      if(i + j + K >= S && i + j <= S) ans++;
    }
  }

  cout<<ans<<endl;

  return 0;
}
