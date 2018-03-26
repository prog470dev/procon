/*
LIS(最長増加部分列)
引数: int n //調べる数列の長さ
返り値: LISの長さ(int)
概要:
	O(nlogn)
	今から調べる数列をa[]とする
	・dp配列をinfで初期化
	・dpの先頭から見て、a[i] <= dp[i]なら書き換える
	  (これを二分探索で高速化している)
	増加部分列はdp[i] < dp[i+1]である
	ex) 6
		1 3 2 3 3 4
		inf inf inf inf inf inf inf //初期化
		  1 inf inf inf inf inf inf //inf → 1 に書き換え
		  1   3 inf inf inf inf inf //inf → 3
		  1   2 inf inf inf inf inf //  3 → 2
		  1   2   3 inf inf inf inf //inf → 3
		  1   2   3 inf inf inf inf //  3 → 3
		  1   2   3   4 inf inf inf //inf → 4
応用:
	・入れ子構造(マトリョーシカみたいなの)に使える
	・二次元ならpairでもって、sort
	  secondのとこだけでLISを求めれば、二次元LIS
*/
#include <algorithm>
#include <iostream>
using namespace std;

const int inf=1e9;

int N;//数列の長さ
const int MAX_N=100010;
int a[MAX_N]; //調べる数列
int dp[MAX_N];

int LIS(){
    for(int i=0; i<N; i++) dp[i]=inf;
    for(int i=0; i<N; i++) *lower_bound(dp,dp+N,a[i])=a[i];
    return lower_bound(dp,dp+N,inf)-dp;
}

// LDS(最長減少部分列)
int LDS(){
    for(int i=0; i<N; i++) a[i]=-a[i];
    for(int i=0; i<N; i++) dp[i]=inf;
    for(int i=0; i<N; i++) *lower_bound(dp,dp+N,a[i])=a[i];
    return lower_bound(dp,dp+N,inf)-dp;
}

// 二次元LIS
pair<int,int> pa[MAX_N]; //調べる数列
int LIS2(){
    sort(pa,pa+N);
    for(int i=0; i<N; i++) dp[i]=inf;
    for(int i=0; i<N; i++) *lower_bound(dp,dp+N,pa[i].second)=pa[i].second;
    return lower_bound(dp,dp+N,inf)-dp;
}

int main(){
    cin>>N;
    int ans;

    //LIS

    for(int i=0; i<N; i++) cin>>a[i];
    ans=LIS();

    //LDS

//    for(int i=0; i<N; i++) cin>>a[i];
//    ans=LDS();

    //LIS2

//    for(int i=0; i<N; i++) {
//        int x,y;
//        cin>>x>>y;
//        pa[i]={x,y};
//    }
//    ans=LIS2();

    cout << ans << endl;
}