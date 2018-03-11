/*
stringの使い方(strとする)

・文字列の連結 ( + )

・文字列の切り出し(substr)

・挿入
	・文字列に文字を挿入(insert)
	・文字列に文字列を挿入

・削除
	・文字を削除(erase)
	・文字列を削除(erase)

・状態を取得
	・空かどうか(empty)
	・文字数を返す(size)

・文字列をscanf,printfで扱う(c_str())

・文字列検索(find)

・文字列置換(replace)
*/


----------------------------
/*切り出し*/

//idxからnum個切り出す
str.substr(idx,num);

----------------------------
/*挿入*/

//str[num]に文字'c'を挿入
str.insert(str.begin()+num,'c');

//str[num]から文字列"abc"を挿入したいとき
str = str.substr(0,num) + "abc" + str.substr(num,str.size()-num);

----------------------------
/*削除*/

//文字str[num]を削除
str.erase(str.begin() + num);

//文字str[num1]からstr[num2-1]まで削除
str.erase(str.begin()+num1,str.begin()+num2);

----------------------------
/*状態取得*/

//空かどうか
if(str.empty())

//文字数を返す
str.size()

----------------------------
/*stringのポインタ*/

//文字列をscanf,printfで扱う
str.c_str()
scanf("%s",str.c_str());
printf("%s\n",str.c_str());

----------------------------
/*文字列検索*/
//※返り値は一致したらインデックスの開始位置
    (複数ある場合は一番小さいやつ)
    一致しなかったら-1(に相当する値)

//"abc"を検索
str.find("abc");

//numよりあとで"abc"を検索
str.find("abc", num);

//"abc"があるかどうか
if(str.find("abc")!=-1)//ある

逆順検索

str.rfind("abc");

----------------------------
/*文字列置換*/

//str[num1]～[num2-1]を"abc"に置き換え
str.replase(num1,num2,"abc");