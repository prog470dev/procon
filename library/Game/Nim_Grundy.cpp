/*

先手が勝つか負けるかを答える問題ならこれ
(最大値最小値等をもとめるならミニマックスなど)
ゲームが進むにつれ減っていくかcheck


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
//----------------------------

#include <string>
#include <set>
#include <iostream>
using namespace std;

int N;
int mx;
int x[100010];

bool Nim(){
    int g=0;
    for(int i=0; i<N; i++){
        g^=x[i];
    }
    return g == 0;//先手Win
}

//実際は石ではないので帰着する
//例)入力nを整数であるように好きに割って相手に渡す
//   素因数が山になるので、山の数を調べる
//   24 = 2^3*3 → 3 1
bool Nim_prime(){
    int g=0;
    for (int i = 2; i <= N; ++i){
        while(N % i == 0){
            g++;
            N /= i;
        }
    }
    return g == 0;
}

//-----------------------------
int mem[100010];
//Nimは自由に取れちゃうので, 石を3個だけしか取れないと制限した時
int grundy(int n){
    if(mem[n] != -1) return mem[n];

    set<int> s;
    for(int i=1; i<4; i++){
        if(n-i>=0) s.insert(grundy(n-i));//パターンあるだけ追加
    }
    int ret=0;
    while(s.find(ret)!=s.end()){
        ret++;//grundy数を求める
    }
    return mem[n]=ret;
}
bool Grundy(){
    int g=0;
    for(int i=0; i<mx+1; i++) mem[i]=-1;
    for(int i=0; i<N; i++) {
        g^=grundy(x[i]);
    }
    return g == 0;
}

string sente = "First";//先手の名前
string gote = "Second";//後手の名前

int main(){

    cin>>N;
    string ans=sente;//先手Win

    for(int i=0; i<N; i++){
        cin>>x[i];
        mx = max(mx, x[i]);
    }
    // Nim(先に取ったら勝ち)

    if(Nim()) ans=gote;

    // Nim(先に取ったら負け)のときは下も使う
    //if (mx == 1 || N % 2) {//山ぜんぶ1個のとき,後手の勝ち
    //    ans=gote;
    //}

    // Grundy(Nimの自由度あり版)

    //if(Grundy()) ans=gote;

    cout << ans << endl;
}