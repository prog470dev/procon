/*
与えられた文字列がnの倍数か求める

・3の倍数 	各桁の 和 が 3の倍数か
・9の倍数	各桁の 和 が 9の倍数か
・11の倍数	奇数桁 - 偶数桁 が 0 か

計算量 O(n)
*/

#include <string>
using namespace std;

bool is3bai(string s){
	ll ret=0;
	REP(i,0,s.size()){
		ret+=(s[i]-'0');
		ret%=3;
	}
	return ret%3==0;
}

bool is9bai(string s){
	ll ret=0;
	REP(i,0,s.size()){
		ret+=(s[i]-'0');
		ret%=9;
	}
	return ret%9==0;
}

bool is11bai(string s){
	ll ret=0;
	int minus=1;
	REP(i,0,s.size()){
		ret+=(-minus)*(s[i]-'0');
		minus=-minus;
	}
	return ret == 0;
}