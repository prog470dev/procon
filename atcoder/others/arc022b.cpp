/*
詰まった点：
・配列imos[]は未定義でも０初期化されると思っていたがされていないようだ
*/

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

  int n, a, b;
  long long imos[1000005] = {};

  cin>>n;
  for(int i=0; i<n; i++){
    cin>>a>>b;
    imos[a]++;
    imos[b+1]--;
  }

  long long ans = imos[0];
  for(int i=1; i<=1000000; i++){
    imos[i] += imos[i-1];
    ans = max(ans, imos[i]);
  }
  cout<<ans<<endl;

  return 0;
}
