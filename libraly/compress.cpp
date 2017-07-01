/*
座標圧縮
O(NlogN)
概要：
  入力座標のレンジを、ユニークな座標の数まで減らす
使い方：
  ものと入力座標のリスト v に対して実行
*/

vector<int> v;                                   // 90, 43, -30, 10, 43, -5, 90, 43
sort(v.begin(), v.end());　                      // -30, -5, 10, 10, 43, 43, 43, 90
v.erase( unique(v.begin(), v.end()), v.end() );　// -30, -5, 10, 43, 90
map<int,int> zip; //zip[k] : ものとの座標kの圧縮座標
map<int,int> unzip; //unzip[l] : 圧縮座標lのもとの座標
REP( i, 0, v.size() ){
  zip[ v[i] ] = i;
  unzip[i] = v[i];
}
