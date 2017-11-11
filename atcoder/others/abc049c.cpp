/*
2016_12_10
mapで条件を絞り、深さ優先探索していくだけ。
(反省)
map、iteratorの使い方を忘れていた。
*/



#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

string s;
map<string ,int> sarray;

bool dfs(string ts, int pos){
  if(pos == ts.size()){
    return true;
  }
  bool flag = false;
  map<string ,int>::iterator it = sarray.begin();
  while(it != sarray.end()){
    if(pos + (*it).second <= ts.size()){
      if(ts.substr(pos, (*it).second) == (*it).first){
        if(dfs(ts, pos + (*it).second)){
          flag = true;
        }
      }
    }
    it++;
  }
  return flag;
}


int main() {

  cin>>s;

  sarray["deam"] = 5;
  sarray["deamer"] = 7;
  sarray["erase"] = 5;
  sarray["eraser"] = 6;

  if(dfs(s, 0)) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

  return 0;
}
