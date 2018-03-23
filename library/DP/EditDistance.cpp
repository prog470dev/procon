/*
EditDistance(編集距離)
引数: string a , string b
返り値: aをbにするコスト
概要:
	dp表を以下の規則で埋める
    初期化
        ・1文字目が一致してたらdp[0][0] = 0
        ・1文字目が一致してなかったらdp[0][0] = 1
    ・文字が一致している
        上、左、左上の中で一番小さいもの

    ・文字が一致していない
	    ・書き換える　左上 + 書き換えコスト
        ・削除　左のLCS + 削除コスト
        ・追加　上のLCS + 追加コスト

	ex) a = "abcd" , b = "eacd", 全コスト1
		  - a b c d
		- 0 1 2 3 4
		e 1 1 2 3 4
		a 2 1 2 3 4
		c 3 2 2 2 3
		d 4 3 3 3 2 <-これを返す。

計算量 O(|a||b|)
*/

#include <string>
#include <iostream>
using namespace std;
const int inf=1e9;

const int edit_string_size = 100010; //|S|
const int edited_string_size = 20; //|T|
int dp[edited_string_size][edit_string_size];
int ChangeCost=1, DeleteCost=1, AppendCost=1;

int EditDistance(string a, string b){
    dp[0][0]=0;
    for(int i = 1; i < a.size()+1; i++) dp[i][0] = dp[i-1][0] + AppendCost;
    for(int j = 1; j < b.size()+1; j++) dp[0][j] = dp[0][j-1] + DeleteCost;

    for(int i = 1; i < a.size()+1; i++){
        for(int j = 1; j < b.size()+1; j++){
            dp[i][j] = min({dp[i-1][j-1] +  (a[i-1] != b[j-1]) * ChangeCost, //書き換え
                            dp[i-1][j] +  AppendCost,  //追加
                            dp[i][j-1] +  DeleteCost   //削除
                           });
        }
    }
    //Debug
    /*
    for(int i = 0; i < a.size()+1; i++) {
        for (int j = 0; j < b.size()+1; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return dp[a.size()][b.size()];
}

int LoopEditDistance(string a, string b){

    dp[0][0]=0;

    int a_s = a.size();
    for(int j = 0; j < b.size(); j++){
        for(int i = 0; i < a.size()*2 + 1; i++){
            dp[(i+1)%a_s][j+1] = min({dp[i%a_s][j] + (a[i%a_s] != b[j]) * ChangeCost, //書き換え
                                      dp[i%a_s][j+1] + AppendCost, //追加
                                      dp[(i+1)%a_s][j] + DeleteCost//削除
                                     });

        }
    }

    //Debug
    /*
    for(int i = 1; i < a.size(); i++) {
        for (int j = 1; j < b.size()+1; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return min<int>(b.size(), dp[0][b.size()]);
}
/*sをtにするコスト */
string s,t;
int main(){
    cin >> s >> t;
    // コストが違うならこれをつかう(書き換え, 削除 , 追加)
    // cin >> ChangeCost >> DeleteCost >> AppendCost;

    int ans;
    ans = EditDistance(t, s);

    // 空文字列かtのループを許しているとき
    //ans = LoopEditDistance(t,s);
    cout << ans << endl;
    return 0;
}