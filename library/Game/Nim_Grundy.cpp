/*
Nim
引数:   山の個数     (int)
返り値: 先手が勝ちか (bool)
概要：
	n山ある。各山にx[i]個石があり、交互に任意個取っていく
	先に石がとれなかったら負け

Misere Nim
引数:   山の個数	 (int)
返り値: 先手が勝ちか (bool)
概要:
	最後の石をとったら負け
	ほぼNim
	山全部が1個しか石を持たないときだけ違う。

Grundy


概要:
	Nimの発展版
	任意個じゃない時に使える事が多い
	負け状態のGrundy数は0
	ある状態のGrundy数はそこから遷移可能な状態のGrundy数の中で
	最小の非負整数

*/
----------------------------
int x[100010];
bool Nim(int n){
	int g=0;
	REP(i,0,n){
		g^=x[i];
	}
	return g!=0;//先手Win
}

//実際は石ではないので帰着する
//例)入力nを整数であるように好きに割って相手に渡す
//   素因数が山になるので、山の数を調べる
//   24 = 2^3*3 → 3 1
string Nim(int n){
	int g=0;
	for (int i = 2; i <= n; ++i){
		while(n % i == 0){
	        g++;
	        n /= i;
	    }
	}
	string ans="First";//先手Win
	if(g==0) ans="Second";//後手Win
	return ans;
}

-----------------------------
//最後取ったら負け
string Misere_Nim(int N){

	int g = 0, ma = 0;
	REP(j, 0, N) {
		int s; cin >> s;
		g ^= s;
		ma = max(ma, s);
	}
	string ans;
	if (ma == 1) {
		if (N % 2) ans="Second";
		else ans="First";
	} else {
		if (g != 0) ans="First";
		else ans="Second";
	}
	return ans;
}
-----------------------------
int mem[10101];
int grundy(int n){
	if(mem[n] != -1) return mem[n];

	set<int> s;
	for(;;){
		s.insert(grundy());//パターンあるだけ追加
	}
	int ret=0;
	while(s.find(ret)!=s.end()){
		ret++;//grundy数を求める
	}
	return mem[n]=ret;
}

int main(){
	int N;cin>>N;
	int g=0;
	REP(i,0,N) g^=grundy(i);
	if(g!=0) printf("First\n");
	else printf("Second\n");
}