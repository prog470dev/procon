/*
bitDP
概要：状態をbitで管理してDPを行う
*/

// 例: 最大となるように足す
// 入力例:
// 5
// 1 -1 3 -2 4


#include <iostream>
using namespace std;

const int MAX_N=16;
int N;
int a[MAX_N];// 全列挙するもの
int dp[1 << MAX_N];

int main() {
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
	for(int mask=0; mask<(1<<N); mask++) {                   // 全状態(2^n)に対して処理
		for(int i=0; i<N; i++) {
			if (mask & (1 << i)) continue; // bitが立っていたら使用済みなのでcontinue
            // bitの立っていない状態に対して処理
			dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + a[i]); // bitを立てて更新
		}
	}
	cout << dp[(1 << N) - 1] << endl; // 全てのbitが立っている
	return 0;
}


