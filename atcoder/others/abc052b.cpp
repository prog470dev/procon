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

  int N;
  string S;

  cin>>N>>S;

  int x=0, ans=0;
  for(int i=0; i<N; i++){
    if(S[i] == 'I') x++;
    else x--;
    ans = max(ans, x);
  }

  cout<<ans<<endl;

  return 0;
}
