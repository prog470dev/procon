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

  string S;
  cin>>S;

  int cnt = 0, ans = 0;
  bool flag = false;
  for(int i = 0; i<S.size(); i++){
    if(!flag && S[i] == 'A') flag = true;
    if(flag) cnt++;
    if(flag && S[i] == 'Z') ans = cnt;
  }

  cout<<ans<<endl;

  return 0;
}
