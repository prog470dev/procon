/**
 * ３点が鋭角かどうかのチェック
 *  入力：　3点の座標 (y, x)
 *  出力：　鋭角かどうかのbool値
*/

#include <iostream>
# include <utility> //for pair
#include <vector>
#include <queue>
#include <cmath>

#define REP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

/*==================================================*/
bool isAcute(pair<double, double> from, pair<double, double> now, pair<double, double> next){

    //ベクトル
    pair<double, double> a = {now.first - from.first, now.second - from.second};
    pair<double, double> b = {next.first - now.first, next.second - now.second};

    double co;

    co = (a.first * b.first + a.second * b.second) /
            ( (sqrt(a.first * a.first + a.second * a.second) * (sqrt(b.first * b.first + b.second * b.second)) );

    bool ret = true;
    if(0.0 <= co && co <= 1.0){ //鋭角ではない
        ret = false;
    }

    return ret;
}


/*==================================================*/
int maint(){

    pair<double, double> a = {1, 0}, b = {0, 0}, c = {0, 1};
    bool ans = isAcute(a, b, c);

    cout<<ans<<endl;

    return 0;
}