#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {

  int n, a, b;
  cin>>n>>a>>b;

  cout<<max(0, a+b-n)<<endl;

  return 0;
}
