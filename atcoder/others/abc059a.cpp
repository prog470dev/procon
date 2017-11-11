#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int main() {

  string s[3];
  cin>>s[0]>>s[1]>>s[2];

  cout<<(char)(s[0][0] - ('a' - 'A'))<<(char)(s[1][0] - ('a' - 'A'))<<(char)(s[2][0] - ('a' - 'A'))<<endl;

  return 0;
}
