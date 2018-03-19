/*
UnionFind_QFW
�g�p��F
// ���̉� (N:�m�[�h�̍ő��)
UnionFind uf(N);

// �A�C�e��ix�ƃA�C�e��iy�������O���[�v���ǂ���(true or false)
uf.same(ix, iy);

// ix�̏�������O���[�v��iy�̏�������O���[�v�𓯂��O���[�v�Ɍ���
uf.merge(ix, iy);
*/
struct UnionFind_QFW {
	vector<int> i2g;         // i2g[i]:�A�C�e��i�̏�������O���[�v�̔ԍ�
	/* �A�C�e���̎�ނ�ς������Ƃ��́���ύX */
	vector<vector<int>> g2i; // g2i[g]:�O���[�vg�ɏ�������A�C�e������

	UnionFind_QFW(int n) {
		i2g.resize(n);
		g2i.resize(n);
		for (int i = 0; i < n; i++) {
			i2g[i] = i;
			g2i[i].assign(1, i); // �A�C�e��i���P���蓖�Ă�
		}
	}

	// �����O���[�v�ɏ������Ă��邩
	bool same(int ix, int iy) {
		return i2g[ix] == i2g[iy];
	}

	// x�̏�������O���[�v��y�̏�������O���[�v������
	void merge(int ix, int iy) {
		if (same(ix, iy)) return; // �����O���[�v�Ȃ牽�����Ȃ�

		// �O���[�vx�̃A�C�e���� > �O���[�vy�̃A�C�e����  �ƂȂ�悤��(�� ��ʓI�ȃ}�[�W�e�N)
		if (g2i[i2g[ix]].size() < g2i[i2g[iy]].size()) {
			swap(ix, iy);
		}

		// gx�̗v�f�� > gy�̗v�f��
		int gx = i2g[ix];
		int gy = i2g[iy];
		for (int j : g2i[gy]) {
			i2g[j] = gx;
		}

		g2i[gx].insert(g2i[gx].end(), g2i[gy].begin(), g2i[gy].end()); // �O���[�v�̌���
		g2i[gy].clear();
	}
};
