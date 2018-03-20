#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
const ll inf = 1e9+7;

int N;
int minimax(int cnt) {
    // 最終盤面の得点を求める
    if (cnt == N) {//終了条件
        int result = 0;

        return result;
    }
    int turn = cnt % 2;
    int ret = (turn == 0 ? -inf : inf);

    for (int i = 0; i < 3; i++) {//ループ
        //　どちらのターンかによってmaxかminを変える
        if (turn == 0) {//先行
            ret = max(ret, minimax(cnt + 1));
        } else {
            ret = min(ret, minimax(cnt + 1));
        }
    }
    return ret;
}

int main() {
    cin>>N;
    int ans=minimax(0);
    cout<<ans<<endl;
    return 0;
}