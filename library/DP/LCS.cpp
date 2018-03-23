/*
LCS(最長共通部分列)
引数: string a , string b
返り値: LCSの長さ(int 型)
概要:
	dp表を以下の規則で埋める
	・文字が一致している   左上のLCS + 1
	・文字が一致していない max(上のLCS、左のLCS)
	ex) a= "abcd" , b = "acd"
		  - a b c d
		- 0 0 0 0 0
		a 0 1 1 1 1
		c 0 1 1 2 2
		d 0 1 1 2 3 <-これを返す。

計算量 O(|a||b|)
*/

#include <string>
#include <iostream>
using namespace std;

const int string_size = 1010; //|S|
int dp[string_size][string_size];

int LCS(string a, string b){

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j]) {//文字が一致している
                dp[i + 1][j + 1] = dp[i][j] + 1; //左上 +1
            }
            else {//文字が一致していない
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);//上か左の最大値
            }
        }
    }
    return dp[a.size()][b.size()];
}

string s,t;
int main(){
    cin>>s>>t;
    int ans = LCS(s,t);
    cout << ans << endl;
    return 0;
}