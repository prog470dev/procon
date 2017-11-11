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

  for(int i = 0; i<S.size(); i++){
    if(i == 5 || i == 13) cout<<" ";
    else cout<<S[i];
  }
  cout<<endl;

  return 0;
}
