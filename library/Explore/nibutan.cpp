/*
二分探索
lb が小さい方
ub が大きい方
答えをmidにして解く
*/

----------------------------------
//答えが整数の時
bool C(ll mid){//ここに条件を書く

	//lbが更新される不等式を書く
	//return ans >= mid;
}


ll nibutan(){
	ll lb=0,ub=inf;
	while(ub-lb>1){
		ll mid=(lb+ub)/2;
		if(C(mid)) lb=mid;
		else ub=mid;
	}
	return lb;
}

-----------------------------------
//答えが小数の時
bool C(double mid){//ここに条件を書く

	//lbが更新される不等式を書く
	//return ans >= mid;
}


double nibutan(){
	double lb=0,ub=inf;
	REP(i,0,100){
		double mid=(lb+ub)/2;
		if(C(mid)) lb=mid;
		else ub=mid;
	}
	return lb;
}