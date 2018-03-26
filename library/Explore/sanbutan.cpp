/*
三分探索
なにかが凸関数で表せる場合に使う
絶対値をとる時などはあやしい(最小値よりはなれていくほど答えも値がはなれていく)
最小値を求める時と最大値をもとめるときで、
不等号が逆になるので注意

例:
 yukicoder No.198
 https://yukicoder.me/problems/no/198
 箱の中身のキャンディーを同じ数にしたい

*/

#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
const ll inf = 1e18;

int N;
ll B;
ll C[11];
ll search(ll mid){
    ll tmp = 0;
    ll a = B;
    for(int i=0; i < N; i++) {
        tmp += abs(mid - C[i]);
        a += C[i] - mid;
    }
    if (a < 0) return inf;
    return tmp;
}

int main() {
    cin>>B>>N;
    ll sum=B;
    for(int i=0; i<N; i++) {
        cin>>C[i];
        sum+=C[i];
    }
    sort(C,C+N);
    ll lb=C[0];
    ll ub=sum/N+1;
    while(ub -lb > 3){
        ll mid1=(lb * 2 + ub) / 3; //三等分して左を選ぶ
        ll mid2=(lb + ub * 2) / 3; //三等分して右を選ぶ
        if(search(mid1) > search(mid2)) lb=mid1; //左側の領域を捨てる
        else ub = mid2;
    }
    ll ans = inf;
    for(ll i=lb; i<ub; i++){//ギリギリのとこは絞れないので愚直に
        ans=min(ans,search(i));
    }
    cout<<ans<<endl;
    return 0;
}