/*
2016_12_28
通ってしまったが、考察が不十分だった。
極端なケースを、早い段階で考えることが必要。
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

  string S;
  cin>>S;

  //int dp[100005] = {};
  int gp = 0, pp = 0, p = 0;

  for(int i=0; i<S.size(); i++){
    if(S[i] == 'g'){
      if(pp < gp) pp++, p++;
      else gp++;
    }else{
      if(pp < gp) pp++;
      else gp++, p--;
    }
  }

  cout<<p<<endl;

  return 0;
}
