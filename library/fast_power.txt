/*
高速な累乗(mod対応版)
引数: aのb乗のmod(long long型)
返り値: 累乗のmod(long long型)

計算量: O(log a)

※modしない場合は mod に inf をいれること

※0のb乗は1になってます。
*/


ll fast_power(ll a, ll b, ll m){
	ll ret=1;
	if(a < 0) {
		a=-a;
		if(b % 2 == 1) ret=-1;
	}
	while(b>0){
		if(b & 1){
			ret*=a;
		}
		a*=a;
		a%=mod;
		ret%=mod;
		b >>= 1;
	}
	return ret;
}