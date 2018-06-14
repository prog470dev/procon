#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, n) for(int i=a; i<n; i++)
const int MOD = 1e9 + 7;

using namespace std;

/*
������

�T�v�F0�ȏ�̐���n���A��������ʂ����Ɏ��R���̘a�ɕ�����ꍇ�̐���MOD
Q(i,j) := ����i����������ʂ����Ɂuj�̎��R���v�̘a�ɕ�����ꍇ�̐�
R(i,j) := ����i����������ʂ����Ɂuj�ȉ��̎��R���v�̘a�ɕ�����ꍇ�̐�

�����F

�Ԃ�l�F

�v�Z�ʁF�n(n^2)

*/

/*==================================================*/
// ��������MOD�����߂�
template<typename T> struct PartitionNumber {
	int n;
	vector<T> _P; vector<vector<T>> _PP, _Q, _R;
	PartitionNumber(int _n) {
		n = _n;
		_P.resize(n + 1);
		_PP.resize(n + 1, vector<T>(n + 1));
		_Q.resize(n + 1, vector<T>(n + 1));
		_R.resize(n + 1, vector<T>(n + 1));

		_Q[0][0] = 1;
		REP(i, 1, n + 1) REP(j, 1, n + 1) {
			_Q[i][j] += _Q[i - 1][j - 1] % MOD;
			if (j <= i) _Q[i][j] += _Q[i - j][j] % MOD;
		}
		REP(i, 0, n + 1) {
			_R[i][0] = _Q[i][0];
			REP(j, 1, n + 1) _R[i][j] = _R[i][j - 1] + _Q[i][j] % MOD;
		}
	}

	int R(int i, int j) {
		return _R[i][j] % MOD;
	}
	int Q(int i, int j) {
		return _Q[i][j] % MOD;
	}
};

/*==================================================*/

PartitionNumber<int> pn(1010);  // 1����1010�܂ł̕�����

int main() {
	cout << "Q(i, j)"  << endl;
	cout << pn.Q(7, 3) << endl; // ����7��3�̎��R���ɕ��������Ƃ��̑g�ݍ��킹����mod
	cout << pn.Q(7, 2) << endl;
	cout << pn.Q(7, 1) << endl;

	cout << "R(i, j)"  << endl;
	cout << pn.R(7, 3) << endl; // ����7��3�ȉ��̎��R���ɕ��������Ƃ��̑g�ݍ��킹����mod
	cout << pn.R(7, 2) << endl;
	cout << pn.R(7, 1) << endl;
	return 0;
}