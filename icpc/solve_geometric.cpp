/*
2017_03_13_AC_
＜疑問点＞
・ふるいを使って予め素数を用意しようとするとメモリ不足を起こす。
＜疑問点＞
・「合成数xはp<=√xを満たす素因数pを持つ」問条件は、
　x=10の場合、素因数2,5(>√10)なので、満たされないのでは？
　＝＞というか、今回は素数であることを判別する必要はない？（逐次的に更新しているし）
　＝＞とりあえず、素数「判定」にしか使わない、という認識で良いかも・・・
*/

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

int gcd(int a,int b)
{

	if (a%b==0) return(b);
	else return gcd(b,a%b);
}

int main() {
  int p, q;
  cin>>p>>q;

	q = q/gcd(p,q);  /*互いに素にした時の分母*/

	int qq = q;
	long long ans = 1;
	for(int j=2; j*j<=qq; j++){
		if(qq % j == 0){
			ans *= j;
			while(qq % j == 0){
				qq /= j;
			}
		}
	}
	if(qq != 1) ans *= qq;

	cout<<ans<<endl;

  return 0;
}
