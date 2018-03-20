/*
三分探索
なにかが凸関数で表せる場合に使う
search(ll mid)に条件かくだけ
最小値を求める時と最大値をもとめるときで、
不等号が逆になるので注意

*/


ll search(ll mid){

}

int main() {
	cin>>B>>N;
	ll sum=B;
	REP(i,0,N) {
		cin>>C[i];
		sum+=C[i];
	}
	if(N==1){
		p(0);
		return 0;;
	}
	sort(C,C+N);
	ll lb=C[0];
	ll ub=sum/N+1;
	while(ub -lb > 3){
		ll mid1=(lb * 2 + ub) / 3;
		ll mid2=(lb + ub * 2) / 3;
		if(search(mid1) > search(mid2)) lb=mid1;
		else ub = mid2;
	}
	ll ans = inf;
	REP(i,lb,ub){
		ans=min(ans,search(i));
	}
	p(ans);
	return 0;
}
