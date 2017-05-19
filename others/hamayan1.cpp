#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

typedef long long ll;
map<ll, int> enumpr(ll n) {
	map<ll, int> V;
	for (ll i = 2; i*i <= n; i++) while (n%i == 0) V[i]++, n /= i;
	if (n>1) V[n]++;
	return V;
}

int main() {

  long long N;
  cin>>N;

  auto v = enumpr(N);

  long long g = 0;
  for(auto a : v){
    g = g ^ a.second;
  }

  if(g == 0) cout<<"Bob"<<endl;
  else cout<<"Alice"<<endl;

  return 0;
}
