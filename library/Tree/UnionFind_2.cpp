/*
Union-Find
�g�p��F
//���̉� (N:�m�[�h�̍ő��)
UnionFind uf(N);

// x�̐e�m�[�h�ԍ���Ԃ�
uf.find(x)

// �m�[�hx�ƃm�[�hy�𓯂��O���[�v�Ɍ���
uf.unite(x, y);

// �m�[�hx�ƃm�[�hy�������O���[�v���ǂ���(true or false)
uf.same(x, y);
*/
const int MAX_N = 100010;
struct UnionFind {
	int par[MAX_N];    // �e�m�[�h�̔ԍ�
	int deph[MAX_N];   // �m�[�h�̐[��

	/* ���ȊO�Ɏ����Ă����f�[�^
	// ��)�؂ł��邩�ǂ���(bool�l)�����ꍇ
	// bool istree[MAX_N];

	*/

	UnionFind(int n) {
		fill(par, par + MAX_N, -1);  // -1�ŏ�����
		for (int i = 0; i<n; i++) {
			par[i] = i;
			deph[i] = 0;

			/* �����Ă����f�[�^�ɂ����ď��������K�v�ȏꍇ
			// istree[i] = true;

			*/
		}
	}

	int find(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			/* �����O���[�v�ɑ����Ă���Ƃ��̏���
			// istree = false;

			*/
			return;
		}
		if (deph[x] < deph[y]) {
			par[x] = par[y];
			/* ���[�g��y�Ƃ��鎞�̏���

			*/
		}
		else {
			par[y] = par[x];
			if (deph[x] == deph[y]) deph[x]++;
			/* ���[�g��x�Ƃ��鎞�̏���

			*/
		}
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}
};