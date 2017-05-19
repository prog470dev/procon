#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {

  int a, b;
  char c;

  cin>>a>>c>>b;

  if(c == '+') cout<<a+b<<endl;
  else cout<<a-b<<endl;

  return 0;
}
