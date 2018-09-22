#include "bits/stdc++.h"
using namespace std;

// 概要：文字列の一致判定や最長共通接頭辞(LCP)の長さを求めることをハッシュを用いて高速に行うもの
// ・LCP(b, l1, r1, l2, r2)=区間[l1, r1)と、ハッシュテーブルがbからなる区間[l2, r2)の文字列のLCPの長さを求める
// ・rh.get(l, r)：[l, r)の文字列のハッシュ値の取得

// 計算量：
// ①ハッシュ値の構築：Ｏ(|S|)
// ②一致する文字列の検索：Ｏ(1)
// ③LCP：Ｏ(log|S|)

template< unsigned mod >
struct RollingHash {
    vector< unsigned > hashed, power;

    inline unsigned mul(unsigned a, unsigned b) const {
        unsigned long long x = (unsigned long long) a * b;
        unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
        asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
        return m;
    }

    RollingHash(const string &s, unsigned base = 10007) {
        int sz = (int) s.size();
        hashed.assign(sz + 1, 0);
        power.assign(sz + 1, 0);
        power[0] = 1;
        for(int i = 0; i < sz; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
        }
    }

    unsigned get(int l, int r) const {
        unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
        if(ret >= mod) ret -= mod;
        return ret;
    }

    unsigned connect(unsigned h1, int h2, int h2len) const {
        unsigned ret = mul(h1, power[h2len]) + h2;
        if(ret >= mod) ret -= mod;
        return ret;
    }

    int LCP(const RollingHash< mod > &b, int l1, int r1, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while(high - low > 1) {
            int mid = (low + high) / 2;
            if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
            else high = mid;
        }
        return (low);
    }
};

int main() {
    string T, P;

    cin >> T;
    cin >> P;
    RollingHash< 1000000007 > rh(T), rh2(P); // ハッシュ値の構築
    for(int i = 0; i + P.size() <= T.size(); i++) {
        if(rh.get(i, i + P.size()) == rh2.get(0, P.size())) { // ハッシュ値同士の比較
            cout << i << endl;
        }
    }
}