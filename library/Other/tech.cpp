/*
文字列→数値
数値→文字列
一行読み込む
切り上げ
四捨五入
最大公約数(約分)
最小公倍数
通分
割り算の比較
lowerbound
upperbound
binary_search

文字列の比較方法(ソート、)

LIS(最長増加部分列)
二部探索
*/


------------------------------
//文字→数値
//(c → num)

ll num = c - '0';

------------------------------
//文字列→数値
//(str → num)

ll num=0;
REP(i,0,str.size()){
	num *= 10;
	num += (str[i] - '0');
}

------------------------------
//数値→文字列
//(num → str)

string str=to_string(num);

------------------------------
//文字列一行読み込み
//(strに読み込む)
//(scanfでstring型は受け取れない)

getline(cin,str);

------------------------------
//切り上げ a/m
a = (a + m - 1)/m;

//四捨五入
a = (double) a / m + 0.5;
------------------------------
//最大公約数( a/b の約分を求める)

ll gcd(ll a,ll b){
	if(b == 0) return a;
	return gcd(b,abs(a-b));
}

//gcc拡張を使う
ll gcd = __gcd(a,b);

------------------------------
//最小公倍数

ll lcm = a/__gcd(a,b)*b;

------------------------------
//通分
//(a/b + c/d)

ll gcd = __gcd(b,d);
ll lcm = b / gcd * d;
ll bunshi = a * d / gcd + c * b / gcd;
ll bunbo = lcm;
double tubun = bunshi/bunbo;

// 通分のあと約分された形にしたい

ll gcd2= __gcd(bunshi,bunbo);
bunshi /= gcd2;
bunbo = bunbo / gcd2;

------------------------------
//割り算の比較
a/b == c/d
//→a*d == b*c

------------------------------
//lower_bound,upper_bound
//lower_boundは a <= k となる k
//upper_boundは a < k となる k
//aが最大値を超えていたら0を返すので注意
//返り値はイテレータ

sort(vt.begin(),vt.end());//忘れずに
ll lb = *lower_bound(vt.begin(),vt.end(),a);
ll ub = *upper_bound(vt.begin(),vt.end(),a);

//binary_search
//aがあるか検索。返り値はbool型
bool exist = binary_search(vt.begin(),vt.end(),a);

------------------------------

