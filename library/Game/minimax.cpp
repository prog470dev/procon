///*
// * ミニマックス法
// * 先手が最大化し、後手が最小化する
// *
// * 例はみんぷろ2018C
// * https://yahoo-procon2018-qual.contest.atcoder.jp/tasks/yahoo_procon2018_qual_c
// */
//
//#include <iostream>
//#include <vector>
//using namespace std;
//typedef long long ll;
//const ll infl=1LL << 60;
//int N;
//ll X[20], C[20], V[20];
//ll dp[20][1 << 18];
//vector<pair<ll, ll>> v;
////---------------------------------------------------------------------------------------------------
//ll memo[20][1 << 18];
//ll f(int n, int mask) {
//    if (0 <= memo[n][mask]) return memo[n][mask];
//    if (n == N) return 0;
//
//    // 売却
//    ll sold = infl;
//    for(int i=0; i<N; i++) if (mask & (1 << i)) sold = min(sold, f(n + 1, mask - (1 << i))); //最小化
//
//    // 購入
//    ll buy = dp[n][mask];
//
//    return memo[n][mask] = max(sold, buy); //最大化
//}
////---------------------------------------------------------------------------------------------------
//int main() {
//    cin >> N;
//    for(int i=0; i<N; i++) cin >> X[i];
//    for(int i=0; i<N; i++) cin >> C[i];
//    for(int i=0; i<N; i++) cin >> V[i];
//
//    for(int n=0; n<N+1; n++) {
//        ll yen = 0;
//        for(int i=0; i<n; i++) yen += X[i];
//
//        for(int mask=0; mask<(1 << N); mask++) {
//            ll co = 0, va = 0;
//            for(int i=0; i<N; i++) if (mask & (1 << i)) co += C[i], va += V[i];
//            if (co <= yen) dp[n][mask] = va;
//            else dp[n][mask] = 0;
//        }
//
//        for(int mask=0; mask<(1 << N); mask++) for(int i=0; i<N; i++) if (mask & (1 << i)) dp[n][mask] = max(dp[n][mask], dp[n][mask ^ (1 << i)]);
//    }
//
//    for(int mask=0; mask<(1 << N); mask++) for(int i=0; i<N; i++) memo[i][mask] = -1;
//    cout << f(0, (1 << N) - 1) << endl;
//    return 0;
//}