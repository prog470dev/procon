/*
 * 行列の演算
 *
 * Mat が二次元vector
 * 行列xベクトル
 * ベクトルx行列
 * 単位行列
 * 行列x行列
 * 行列累乗 O(log N)
 * print
 * 平行移動(x方向)
 * 平行移動(y方向)
 * 反時計回り90度回転
 * 時計回り90度回転
 */
#include <iostream>
#include <vector>
#define REP(i, n, N) for(ll i = (n); i < (N); i++)
using namespace std;
typedef long long ll;
using TN = ll; using Vec = vector<TN>; using Mat = vector<Vec>;
Vec mulMatVec(Mat a, Vec b) {
	int n = b.size(); Vec ret(n, 0);
	REP(i, 0, n) REP(j, 0, n) ret[i] = ret[i] + a[i][j] * b[j];
	return ret;
}
Vec mulVecMat(Vec a, Mat b) {
	int n = b.size(); Vec ret(n, 0);
	REP(i, 0, n) REP(j, 0, n) ret[i] = ret[i] + a[j] * b[j][i];
	return ret;
}
Mat identityMat(int n) {
	Mat m(n, Vec(n, 0));
	REP(i, 0, n) m[i][i] = 1;
	return m;
}
Mat mulMatMat(Mat a, Mat b) {
	int n = a.size(); Mat ret(n, Vec(n, 0));
	REP(i, 0, n) REP(j, 0, n) REP(k, 0, n) ret[i][j] = ret[i][j] + a[i][k] * b[k][j];
	return ret;
}

Mat fastpow(Mat x, ll n) {
	Mat ret(x.size(), Vec(x.size(), 0));
	REP(i, 0, x.size()) ret[i][i] = 1;
	while (0 < n) { if ((n % 2) == 0) { x = mulMatMat(x, x); n >>= 1; } else { ret = mulMatMat(ret, x); --n; } }
	return ret;
}
void printVec(Vec a) { cout << "[\t"; REP(i, 0, a.size()) cout << a[i] << "\t"; cout << "]" << endl; }
void printMat(Mat a) { REP(i, 0, a.size()) printVec(a[i]); }

Mat TranslationX(Mat x, ll dx){
	return {
		{1, 0, dx},
		{0, 1, 0},
		{0, 0, 1}
	};
}

Mat TranslationY(Mat x, ll dy){
	return {
		{1, 0, 0},
		{0, 1, dy},
		{0, 0, 1}
	};
}

// 反時計時計回り
Mat rotate90() {
	return {
		{0, -1, 0}, // cos(90), -sin(90)
		{1, 0, 0},  // sin(90), cos(90)
		{0, 0, 1}
	};
}

// 時計回り
Mat rotate90rev() {
	return {
		{0, 1, 0}, // cos(-90), -sin(-90)
		{-1, 0, 0},  // sin(-90), cos(-90)
		{0, 0, 1}
	};
}
