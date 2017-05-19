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

  string s;
  cin>>s;

  bool flag[2] = {false, false};
  for(int l=0; l<s.size()-1; l++){
    int st = 1;
    if(s[l] == s[l+1]){
      cout<<l+1<<" "<<l+2<<endl;
      return 0;
    }
    if(l < s.size() - 2 && s[l] == s[l+2]){
      cout<<l+1<<" "<<l+3<<endl;
      return 0;
    }
  }

  cout<<-1<<" "<<-1<<endl;

  return 0;
}
