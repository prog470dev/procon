#include <iostream>
#include <map>
#include <vector>

using namespace std;

/* 座標圧縮
概要：入力座標のレンジを、ユニークな座標の数まで減らす

使い方：ものと入力座標のリスト v に対して実行

計算量：Ｏ(NlogN)

*/

/*==================================================*/

/*==================================================*/

/*==================================================*/

int main() {
	vector<int> v;                                //  90, 43, -30, 10, 43, -5, 90, 43
	v.emplace_back(90);
	v.emplace_back(43);
	v.emplace_back(-30);
	v.emplace_back(10);
	v.emplace_back(43);
	v.emplace_back(-5);
	v.emplace_back(90);
	v.emplace_back(43);

	sort(v.begin(), v.end());                     // -30, -5, 10, 10, 43, 43, 43, 90
	v.erase(unique(v.begin(), v.end()), v.end()); // -30, -5, 10, 43, 90

	map<int, int> zip;   // zip[k] : もとの座標kの圧縮座標
	map<int, int> unzip; // unzip[l] : 圧縮座標lのもとの座標
	for (int i = 0; i < v.size(); i++) {
		zip[v[i]] = i;
		unzip[i] = v[i];
	}

	cout << "zipの対応" << endl;
	for (auto itr : zip) {
		cout << itr.first << ":" << itr.second << endl;
	}
	cout << endl;
	cout << "unzipの対応" << endl;
	for (auto itr : unzip) {
		cout << itr.first << ":" << itr.second << endl;
	}
	return 0;
}