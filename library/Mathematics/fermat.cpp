/*
フェルマーの小定理を用いた,組み合わせの余りを求める問題の高速化
-------------------------------
<解説>
フェルマーの小定理
aとpが互いに素なとき
a^(p-1) ≡ 1 (mod p)

両辺にa^(-1)をかけると

a^(p-2) ≡ a^(-1) (mod p)

とできる.　これを利用して nCr = n! * (1/r!) * (1/(n-r)!) を pで割った余りは
n! * (1/r!) * (1/(n-r)!)　≡　n! * (r!)^(p-2) * (n-r)! (mod p)
とできるので, 右辺を求める(combine関数).
n! (factrial) はdpで求める.
(1/r!) (inverse) は繰り返し2乗法(fast_pow関数)によって(r!)^(p-2)求める.

-------------------------------
<使い方> nCr % mod の求め方

const ll mod = 1e9+7;
int n,r;

FermatCombination fc(n, mod);//初期化 と nCi % mod の計算
ll ans = fc.combine(n,r); //nCr % modの値の取得


*/

//--------------------------------------------------------------

class FermatCombination {
private:
    long long factrial[101010]; //階乗を保持
    long long inverse[101010];  //逆元を保持
    long long MOD;

public:
    FermatCombination(int size, long long mod);
    long long combine(int n, int k);
    long long fast_pow(long long x, int n);
};


FermatCombination::FermatCombination(int size, long long mod) {

    MOD = mod;

    factrial[0] = 1;
    inverse[0] = 1;

    for (int i = 1; i <= size; i++) {
        factrial[i] = (factrial[i - 1] * i) % MOD;  //階乗を求める
        inverse[i] = fast_pow(factrial[i], (int) MOD - 2) % MOD; // フェルマーの小定理で逆元を求める
    }
}

long long FermatCombination::combine(int n, int k) {
    return factrial[n] * inverse[k] % MOD * inverse[n - k] % MOD;
}

long long FermatCombination::fast_pow(long long x, int n) { //x^n 計算量O(logn)
    long long ans = 1;
    while (n > 0) {
        if ((n & 1) == 1) {
            ans = ans * x % MOD;
        }
        x = x * x % MOD; //一周する度にx, x^2, x^4, x^8となる
        n >>= 1; //桁をずらす n = n >> 1
    }
    return ans;
}