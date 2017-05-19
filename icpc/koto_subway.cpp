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

double D, E;

int main() {
  while(1){
    cin>>D>>E;
    if(D==0 && E==0) break;
    double ans = (double)1e9;
    for(double x = 0.0; x <= D; x += 1.0){
      double y = D - x;
      ans = min(ans, fabs(sqrt(x*x + y*y) - E));
    }
    printf("%.4lf\n", ans);
  }
  return 0;
}
