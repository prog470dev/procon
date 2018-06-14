/**
 * SegmentTree
 *  - 概要
 *      - クエリに対して連結成分を作成
 *  - 時間計算量
 *      - 区間の最小値クエリに対する問題
 *       	update:xをvalに変更するO(log n)
 *	        getmin:[a,b)の最小値O(log n)
 *      - 区間の合計クエリに対する問題
 *	        add:kにvalを追加するO(log n)
 *       	getsum:[a,b)の合計値O(log n)
 * - メモ
 * 		- 変更・答えのクエリが多いときに有効
 * 		- 添え字に注意
*/

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

/*==================================================*/
/* minimum query (RMQ) */
struct SegmentTree_min {
private:
    int n;
    vector<int> node;

public:
    SegmentTree_min(vector<int> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

    int getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];

        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};


/* sum_query */
struct SegmentTree_sum {
private:
    int n;
    vector<int> node;
public:
    SegmentTree_sum(vector<int> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void add(int k, int val) {
        k += (n - 1);
        node[k] += val;

        while(k > 0) {
            k = (k - 1) / 2;
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    int getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];

        int vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        int vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

/*==================================================*/
int main(){
	
    int N;
    int i=0, v=5;
    int l=10, r=20; 

    //区間最小値のセグ木
    SegmentTree_min seg_min( vector<int>(N, 0) );   //初期化
    seg_min.update(i, v);   //i番目の要素をvに変更
    seg_min.getmin(l,r);   //l番目の要素からr番目の要素までの中で最小の値

    //区間合計のセグ木
    SegmentTree_sum seg_sum( vector<int>(N, 0) );   //初期化
    seg_sum.add(i, v);     //i番目の要素にvを加算
    seg_sum.getsum(l,r);   //l番目の要素からr番目の要素までの合計値


	return 0;
}