/*
半分全列挙
O(N^2*logN)
概要：
　全て全列挙できない場合、２つの部分に分けてそれぞれで列挙し、
　条件の合うものを組み合わせる。
変数：
  N: リストの長さ（全て同じ長さ）
  A,B,C,D: それぞれ要素を一つずつ選択できるリスト　
  ans: 答え(条件を満たす組み合わせの数)
サンプル:
  ４つのリストそれぞれから、要素を一つずつ選択し、
  合計が０になる組み合わせの数を出力する。
  （複数同じ数があっても別扱い）
*/


int N;
int ans;
vector<ll> A,B,C,D,CD;

//入力処理
cin>>N;
ll tmp;
REP(i,0,N) cin>>tmp, A.push_back(tmp);
REP(i,0,N) cin>>tmp, B.push_back(tmp);
REP(i,0,N) cin>>tmp, C.push_back(tmp);
REP(i,0,N) cin>>tmp, D.push_back(tmp);

//半分の組み合わせを列挙
REP(i,0,C.size()){
  REP(j,0,D.size()){
    CD.push_back(C[i]+D[j]);
  }
}
sort(CD.begin(), CD.end());

ans = 0;
REP(i,0,A.size()){
  REP(j,0,B.size()){
    ll cd = -(A[i]+B[j]);
    //条件を満たす組み合わせの個数
    ll cnt = upper_bound(CD.begin(),CD.end(),cd) - lower_bound(CD.begin(),CD.end(),cd);
    ans += cnt;
  }
}
