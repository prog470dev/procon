/*
二分探索
lb が小さい方
ub が大きい方
答えをmidにして解く
*/


#include <algorithm>
#include <vector>
#include <iostream>
typedef long long ll;
using namespace std;
const ll inf = 1e18;


/*例: 数列Aで,整数x > Ai となるAiがK個ある最小の整数xを求めよ*/
int K;
vector<int> vt{1,3,5,7};
bool C(ll mid){//ここに条件を書く

    //lbが更新される不等式を書く
    return lower_bound(vt.begin(), vt.end(), mid) - vt.begin() < K;
}


ll Nibutan(ll lb, ll ub){
    while(ub-lb>1){
        ll mid=(lb+ub)/2;
        if(C(mid)) lb=mid;
        else ub=mid;
    }
    return lb;
}

/*例: ルート2をもとめよ, 絶対誤差は1e(-9)まで許容*/
bool C_d(double mid){//ここに条件を書く

    //lbが更新される不等式を書く

    return mid*mid < 2;
}


double Nibutan_d(double lb, double ub){
    int n=100; //ループ回数
    for(int i=0; i<n; i++){ //十分回まわす(2^(-n)ずつ減って行く)
        double mid=(lb+ub)/2;
        if(C_d(mid)) lb=mid;
        else ub=mid;
    }
    return lb;
}

int main() {
    //cin>>K;
    //ll ans = Nibutan(0, 8);//lb = 0 , ub = infなど
    //cout<<ans<<endl;

    double ans = Nibutan_d(0, 2);
    printf("%.10lf\n", ans);
    return 0;
}