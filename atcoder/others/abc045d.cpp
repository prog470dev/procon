/*
解法：
・３×３のエリアは、左上のマスさえ指定すれば特定できる。
・黒いマスが影響を及ぼすエリア（の左上）をmapでカウントしていく。
詰まったポイント：
・探索場所が範囲外のときの処理を忘れていた。
・イテレータをインクリメントするのを忘れていた。
・最後の縦横の掛け算はlonglongになる。
・mapの第２要素へのアクセスは、「second()」でなく「second」。
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {

  long long H, W, N;
  vector<int> a, b;
  cin>>H>>W>>N;

  for(int k=0; k<N; k++){
    int ta, tb;
    cin>>ta>>tb;
    a.push_back(ta);
    b.push_back(tb);
  }

  map<pair<int, int>, int> m;
  for(int k=0; k<N; k++){
    for(int i=a[k]-2; i<=a[k]; i++){
      for(int j=b[k]-2; j<=b[k]; j++){
        if(i < 1 || H < i+2 || j < 1 || W < j+2) continue;
        m[make_pair(i,j)]++;
      }
    }
  }

  int ans[9] = {};
  map<pair<int, int>, int>::iterator it = m.begin();
  while(it != m.end()){
    ans[(*it).second - 1]++;
    it++;
  }

  cout<<(W-2)*(H-2) - m.size()<<endl;
  for(int i=0; i<9; i++){
    cout<<ans[i]<<endl;
  }

  return 0;
}
