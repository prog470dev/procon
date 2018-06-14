#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
いもす法(1次元、2次元)

概要：累積和を用いて複数要素の重なり、深さを求める
①1次元：開始部分を+1、終了部分の次を-1、その後→方向に加算
②2次元：
(y1, x1)～(y2, x2)の範囲が与えられたら、
(y1, x1)を+1、(y2+1, x2+1)を+1、(y2+1, x1)を-1、(y1, x2+1)を-1
その後、→方向に加算し、↓方向に加算

引数：
①int L (1次元配列の幅)
②int H, int W (2次元配列の高さと幅)

返り値：
①vector<int> (累積和計算後の1次元配列)
②vector<vector<int>> (累積和計算後の2次元配列)

計算量：
①1次元での要素の個数をN、範囲をLとすると
 Ｏ(N * L)　⇒　Ｏ(N + L)
②2次元での要素の個数をN、範囲をH*Wとすると
 Ｏ(N * H * W)　⇒　Ｏ(N + H * W)

注意：配列のサイズは1つ大きくとる
*/

/*==================================================*/
// 範囲(1次元配列)
vector<pair<int, int>> vp;  // l , r

// 範囲(2次元配列)
vector<pair<int, int>> vp1; // y1, x1
vector<pair<int, int>> vp2; // y2, x2

/*==================================================*/
// ○1次元
vector<int> Imos1(int L) {
	vector<int> vi1(L + 1, 0);

	// 範囲内なら+1, 範囲外なら-1
	for (int i = 0; i < vp.size(); i++) {
		vi1[vp[i].first]++;
		vi1[vp[i].second + 1]--;
	}
	// 累積和を求める
	for (int i = 1; i < vi1.size(); i++) {
		vi1[i] += vi1[i - 1];
	}

	return vi1;
}

// ○2次元
vector<vector<int>> Imos2(int H, int W) {
	vector<vector<int>> vi2(H + 1, vector<int>(W + 1));

	// 範囲内なら+1, 範囲外なら-1
	for (int i = 0; i < vp1.size(); i++) {
		vi2[vp1[i].first][vp1[i].second]++;
		vi2[vp2[i].first + 1][vp2[i].second + 1]++;
		vi2[vp1[i].first][vp2[i].second + 1]--;
		vi2[vp2[i].first + 1][vp1[i].second]--;
	}
	// 累積和を求める
	for (int i = 0; i < vi2.size(); i++) {
		for (int j = 1; j < vi2[i].size(); j++) {
			vi2[i][j] += vi2[i][j - 1];
		}
	}
	for (int j = 0; j < vi2[0].size(); j++) {
		for (int i = 1; i < vi2.size(); i++) {
			vi2[i][j] += vi2[i - 1][j];
		}
	}

	return vi2;
}

/*==================================================*/

int main() {
	// ①1次元いもす
	// 例1)0時から12時の間で、2時から6時、4時から9時に客が一人いた場合の各時刻における人数
	int len = 12;  // 範囲

	// 範囲l～rを入力(l<=r)
	vp.emplace_back(2, 6);
	vp.emplace_back(4, 9);

	vector<int> vi1 = Imos1(len);

	// vi1の重なり具合
	cout << "例1" << endl;
	for (int i = 0; i < len + 1; i++) {
		cout << i << "=" << vi1[i] << endl;
	}


	// ②2次元いもす
	// 例2)(0, 0)～(3, 3)の範囲で(1, 1)～(2, 3)、(1, 0)～(3, 2)の範囲に関する重なり
	int h = 4, w = 4;  // 高さ, 幅

	// 範囲(y1, x1)～(y2, x2)を入力(y1<=y2, x1<=x2, vp1.size()==vp2.size())
	vp1.emplace_back(1, 1);
	vp2.emplace_back(2, 3);

	vp1.emplace_back(1, 0);
	vp2.emplace_back(3, 2);

	vector<vector<int>> vi2 = Imos2(h, w);

	// vi2の重なり具合
	cout << endl << "例2" << endl;
	for (int i = 0; i < h + 1; i++) {
		for (int j = 0; j < w + 1; j++) {
			cout << vi2[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}