/*
しゃくとり法
O(N)
概要：
  条件を満たす最大長を求める。
変数：
  N: リストの長さ
  l:　左端の位置
  r:　右端の位置
  ans: 答え（条件を満たす最大長）
サンプル:
  同じA[i]が２個以上含まれない最大範囲を求める
*/

int N;
int A[100010];

//入力
cin>>N;
REP(i,0,N) cin>>A[i];

int ans = 0;
int cnt[100010];
REP(i,0,N) cnt[i] = 0;

int l = 0, r = 0;
//左端は右端を追い越さない
while(l <= r){
  while(r < N){
    //条件を満たさないなら右端を伸ばさない
    if(cnt[A[r]]+1 == 2) break;
    ans = max(ans,r-l+1);
    cnt[A[r]]++;
    r++;
  }
  cnt[A[l]]--;
  l++;
}
