/*
 * 区間DP
 *
 * dp[L][R] := 区間[L,R]についての何か
 * メモリ制約的に O(N^2)くらい
 *
 * 取り除く問題だとありうる.
 *
 * よくある方針として
 * dp[L][R] を　dp[L+1][R-1] や　dp[L+1][R] + dp[L][R-1]で更新する
 * (つまり片側を固定して, 小さい区間から大きい区間へ)
 *
 * L, Rが小さいところから回して最終的にdp[0][N-1]を答えとする
 *
 * 状態遷移を必ず考えること(どの区間の情報が欲しいのか, 更新できる条件は何か)
 * 絵をかくこと
 */

// 例: だるま落とし
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=jp

#include <iostream>
#include <algorithm>
#define REP(i,n,N) for(int i=(n); i<(N); i++)
using namespace std;

int dp[310][310];
int n;
int w[310];
int main() {
    while(cin>>n, n){
        REP(i,0,n) REP(j,0,n) dp[i][j] = 0;
        REP(i,0,n) cin>>w[i];
        for(int k=1;k<n;k++){ //区間(k=1で2つなので注意)
            REP(L,0,n-k){//区間の左
                int R = L + k; //区間の右
                // 更新できる時の条件(中身は全部取り除けている)と値の更新
                if(dp[L+1][R-1] == k-1) dp[L][R] = max(dp[L][R], dp[L+1][R-1] + (abs(w[L]-w[R])<=1)*2);
                //その範囲について, 区間の区切り方で回す(絶対いるのでここはいじらない)
                REP(i,L,R) dp[L][R] = max(dp[L][R], dp[L][i] + dp[i+1][R]);
            }
        }
        p(dp[0][n-1]);
    }

    return 0;
}

