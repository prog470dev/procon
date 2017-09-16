/*
累積和

概要：ある範囲での部分和を求める

返り値：
○1次元：CumulativeSum1　→　vector<int>
　　　　 getSum1　→　int
○2次元：CumulativeSum2　→　vector<vector<int>>
		 getSum2　→　int

計算量：1次元での範囲をLとすると
		Ｏ(L)　⇒　Ｏ(1)
		2次元での範囲をH*Wとすると
		Ｏ(H*W)　⇒　Ｏ(1)

*/

○1次元
// 累積和の生成
vector<int> CumulativeSum1(vector<int> v) {
	for (int i = 1; i < v.size(); i++) {
		v[i] += v[i - 1];
	}
	return v;
}
// (l, r)間での参照(l<=r, l>=0, r<v.size())
int getSum1(int l, int r, vector<int> v) {
	if (l == 0) return v[r];
	else return v[r] - v[l - 1];
}

○2次元
// 累積和の生成
vector<vector<int>> CumulativeSum2(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 1; j < v[i].size(); j++) {
			v[i][j] += v[i][j - 1];
		}
	}
	for (int j = 0; j < v[0].size(); j++) {
		for (int i = 1; i < v.size(); i++) {
			v[i][j] += v[i - 1][j];
		}
	}
	return v;
}
// (x1, y1)～(x2, y2)間での参照(x1<=x2, y1<=y2, x1>=0, y1>=0, x2<v.size(), y2<v[i].size())
int getSum2(int x1, int y1, int x2, int y2, vector<vector<int>> v) {
	if (x1 == 0 && y1 == 0) return v[y2][x2];
	else if (x1 == 0) return v[y2][x2] - v[y1 - 1][x2];
	else if (y1 == 0) return v[y2][x2] - v[y2][x1 - 1];
	else return v[y2][x2] - v[y1 - 1][x2] - v[y2][x1 - 1] + v[y1 - 1][x1 - 1];
}
