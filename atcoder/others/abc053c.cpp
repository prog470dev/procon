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

  long long X;
  cin>>X;

  if(X <= 11*(X/11) + 6){
    if(X % 11 == 0) cout<<2 * (X / 11)<<endl;
    else cout<<2 * (X / 11) + 1<<endl;
  } else{
    cout<<2 * (X / 11) + 2<<endl;
  }

  return 0;
}
