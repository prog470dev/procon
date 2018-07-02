/*
 * 行列累乗 O(log N)
 * 行列のべき乗を繰り返し二乗法で求める
 *
 * mat が二次元vector
 */

// フィボナッチの例
#include <iostream>
#include <vector>
#define REP(i,n,N) for(ll i=(n); i<(N); i++)
typedef long long ll;
using namespace std;
const ll mod=1e9+7;

typedef vector<ll> vec;
typedef vector<vec> mat;

ll n;
//H = 行列の縦, W = 行列の横
ll H, W;

//A*B
mat mul(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size(),0));
    REP(i, 0, A.size())
    REP(k, 0, B.size())
    REP(j, 0, B[0].size())
    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

//A^n
mat mat_pow(mat A, long long n){
    mat B(A.size(), vec(A.size(), 0));
    REP(i, 0, A.size()) B[i][i] = 1;
    while(n > 0){
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main(){
    cin>>H>>W;
    mat A(H, vec(W,0));//行列の 縦 x 横

    //ここで定式化した行列を代入する
    A[0][0] = A[1][0] = A[0][1] = 1;
    A[1][1] = 0;

    ll n = 10;
    A = mat_pow(A, n-1); //繰り返し二乗法
    mat B(H, vec(1,0));

    B[0][0] = 1, B[1][0] = 0;
    mat ans = mul(A, B);
    cout<<ans[0][0]<<endl;
}