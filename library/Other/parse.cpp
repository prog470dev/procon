/*
四則演算パーサ
概要：
  stringで入力された式を計算する。
*/

#include <string>
#include <cctype>
typedef string::const_iterator State;

long long expression(State &);
long long term(State &);
long long number(State &);
long long factor(State &);

// 四則演算の式をパースして、その評価結果を返す。
long long expression(State &begin) {
    long long ret = term(begin);
    for (;;) {
        if (*begin == '+') {
            begin++;
            ret += term(begin);
        } else if (*begin == '-') {
            begin++;
            ret -= term(begin);
        } else {
            break;
        }
    }
    return ret;
}

// 乗算除算の式をパースして、その評価結果を返す。
long long term(State &begin) {
    long long ret = factor(begin);
    for (;;) {
        if (*begin == '*') {
            begin++;
            ret *= factor(begin);
        } else if (*begin == '/') {
            begin++;
            ret /= factor(begin);
        } else {
            break;
        }
    }
    return ret;
}

// 括弧か数をパースして、その評価結果を返す。
long long factor(State &begin) {
    if (*begin == '(') {
        begin++; // '('を飛ばす。
        long long ret = expression(begin);
        begin++; // ')'を飛ばす。
        return ret;
    } else {
        return number(begin);
    }
}

// 数字の列をパースして、その数を返す。
long long number(State &begin) {
    long long ret = 0;
    while (isdigit(*begin)) {
        ret *= 10;
        ret += *begin - '0';
        begin++;
    }
    return ret;
}

/*サンプル*/
long long main(){
  string s;
  cin>>s;
  State begin = s.begin();
  long long ans = expression(begin);
  cout << ans << endl;
  return 0;
}
