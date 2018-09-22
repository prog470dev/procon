/*
 * 文字列置換
 * 検索文字列に一致した文字列を全て置換する
 *
 * 再帰バージョンと再帰じゃないバージョンがある
 *
 *
 * 例: 対象　s = aabaaabaa
 * 　  検索　before = aba
 *     置換  after = b
 *
 *     再帰あり (rec = true)
 *     a"aba"aabaa -> "aba"aabaa -> ba"aba"a -> b"aba" -> bb
 *
 *     再帰なし (rec = false)
 *     a "aba" a "aba" a -> ababa
 *
 */


#include "string"
#include "iostream"
using namespace std;

string replaceAll(string &replacedStr, string from, string to, bool recursive=false) {
    auto pos = replacedStr.find(from);
    int toLen = to.length();
    int fromLen = from.length();
    if (fromLen==0||pos==string::npos) {
        return replacedStr;
    }
    if(!recursive) {
        while ((pos + fromLen <= replacedStr.length()) && ((pos = replacedStr.find(from, pos)) != string::npos)) {
            replacedStr.replace(pos, fromLen, to);
            pos += toLen;
        }
    }
    else{
        while ((pos = replacedStr.find(from)) != string::npos) {
            replacedStr.replace(pos, fromLen, to);
        }
    }
    return replacedStr;
}

string s;
int main() {
    s = "aabaaabaa";
    string before = "aba";
    string after = "b";
    bool rec = false; // please true if you want to replace recursively.
    replaceAll(s, before, after, rec);
    cout << s <<endl;
    return 0;
}