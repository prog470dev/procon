/*
●hypot(a, b)

・2点間a,bの距離を返す
・hypotenuse（斜辺）
・sqrt(a*a + b*b)と同じ
・返り値はdouble型
*/

/*
●__builtin_popcount(unsigned int)

・1が立っているbit数を返す
・例)__builtin_popcount(10) = 2
*/

/*
●next_permutation(v.begin(), v.end())

・全ての組み合わせを列挙
・sortが必要!!
・逆順の全列挙としては、prev_permutation(v.begin(), v.end())

・使い方
vector<int> v;
// vにデータ追加
//
sort(v.begin(), v.end());
do{
	// 処理
	//
}while(next_permutation(v.begin(), v.end()));
// (v.size())!の順列が終わったらfalseを返す

*/

/*
●1行読み込み(空白こみ)
・例1
string s
getline(cin, s)
// 改行コードは無視される

・(注意)数値<改行>文字列<改行>の場合
int n;
string s;
cin >> n;
getline(cin, s);
// getlineは改行だけを読みこんで終了⇒sには何も入らない

// ignore()を使う
cin >> n;
cin.ignore(); // 次の改行文字まで(改行文字を含めて)最大1文字読み捨てる。
              // 1文字だと駄目な場合は cin.ignore(/*読み飛ばしたい最大文字数*/); とすれば良い。
getline(cin, s);
*/

/*
●重複要素の削除
sort(v.begin(), v.end());
v.erase( unique(v.begin(), v.end()), v.end() );

・setにinsertしてfindするより高速
*/

/*
●底の変換公式
・log(a, b) = log(x, b) / log(x, a)
・xは何でもよい
・log(底, 基数)
・Mathライブラリには底がe, 2, 10の時しかない
*/
