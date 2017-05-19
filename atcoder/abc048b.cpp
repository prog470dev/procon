#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

long long func(long long n, long long x){
  if(n >= 0) return n / x + 1;
  else return 0;
}

int main() {
  long long a, b, x;
  cin>>a>>b>>x;

  cout<<func(b, x) - func(a-1, x)<<endl;

  return 0;
}
