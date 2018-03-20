/*
vectorの使い方(vtとする)

・初期化
	・要素数指定
	・初期値も指定
	・バラバラの初期値を指定

・データの追加
	・後ろに追加(push_back) O(1)
	・二つ以上の同時追加(emplase_back)
	・挿入(insert) O(N)

・データの削除
	・後ろを削除(pop_back) O(1)
	・任意の箇所を削除(erase) O(N)

・状態を取得
	・空かどうか(empty)
	・要素数を返す(size)

・要素を取得
	・先頭要素の参照(front())
	・最後の要素の参照(back())

・状態の変更
	・空にする(clear)
	・メモリ解放(shrink_to_fit)

相性の良い関数
・count
・accumulate
・find
・reverse
・sort

*/


----------------------------
/*初期化*/


//要素数を指定する初期化
vector<int> vt(123);//123個の動的配列(初期値0)

//初期値も指定
vector<int> vt(123,inf);//要素数123,全部inf

//※push_backすると124個目に値が格納される

//バラバラの初期値を指定
vector<int> vt{1,2,3};//{1, 2, 3}

----------------------------
/*デバッグ用*/


//範囲外でエラーをだす
vt.at(num) = 123; //numがvtの範囲外ならエラー表示

----------------------------
/*要素の追加・挿入*/


//後ろに追加
vt.push_back(123); //123を追加

//二つ以上追加するときに自動でやってくれる
//pair<int,int> 型なら、それにしてくれる
vt.emplase_back(1,2);

//挿入
//もちろんサイズは増える
vt.insert(v.begin()+3,123); //vt[3]の位置に123を挿入

----------------------------
/*要素の削除*/


//※削除は空のvectorではerrorを出すので注意

//後ろを削除
vt.pop_back();

//任意の箇所を削除
//削除箇所より後ろは前に詰められる
vt.erase(vt.begin()+5) //vt[5]を削除

//範囲を指定して削除
vt.erase(vt.begin()+2,vt.begin()+5); //vt[2] ～ vt[4]を削除

----------------------------
/*状態の取得*/


//空かどうか(bool型)
if(vt.empty())

//size(unsigned )
vt.size(); //sizeof(vt)と同じ

----------------------------
/*要素の取得*/


//※参照は空のvectorではerrorを出すので注意

//先頭要素
vt.front();//(vt[0]とおなじ)

//最後の要素
vt.back();

----------------------------
/*状態の変更*/


//空にする
vt.clear();

//メモリ解放(clearの後に)
vt.shrink_to_fit();

----------------------------
/*便利な関数*/


//ある要素の数をカウント
ll cnt = count(vt.begin(),vt.end(),123); //要素123の数を返す

//全要素加算する
ll sum = accumulate(vt.begin(),vt.end());

//ある要素の最初の位置(イテレータ)を返す
//なかったらvt.end()が返る
//※何回も検索するならsortしてlower,upperを使うべき
auto itr = find(vt.begin(),vt.end(),123); //要素123の最初の位置

//反転する
reverse(vt.begin(),vt.end());

//ソートする(辞書順最小)
sort(vt.begin(),vt.end());

//逆順ソート
sort→reverse