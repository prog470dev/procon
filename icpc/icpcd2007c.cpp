/*
要素数３の配列ですべて管理しようと知るから、ケアレスミスが増える。
特に今回は、途中でソートする必要がないかrあ、別配列で値を持っても良いはず。
（メモ）vectorのvectorのsortは、中身のvectorの一つ目の要素をもとに並べ替えられる
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

  int n, w, d, p, s;

  while(1){
    cin>>n>>w>>d;
    if(n==0 && w==0 && d==0) break;

    vector< vector<int> > v;

    vector<int> a(3);
    a[0] = w*d;
    a[1] = w;
    a[2] = d;
    v.push_back(a);

    for(int i=0; i<n; i++){
      cin>>p>>s;
      int sd = s % (2*v[p-1][1] + 2*v[p-1][2]);
      vector<int> b1(3), b2(3);

      if(sd < v[p-1][1]){
        //cout<<"case1"<<endl;
        b1[0] = v[p-1][0] * sd / v[p-1][1];
        b2[0] =  v[p-1][0] - b1[0];
        b1[1] = sd; b2[1] = v[p-1][1] - b1[1];
        b1[2] = b2[2] = v[p-1][2];
      }else if(v[p-1][1] < sd && sd < v[p-1][1] + v[p-1][2]){
        //cout<<"case2"<<endl;
        b1[0] = v[p-1][0] * (sd - v[p-1][1]) / v[p-1][2];
        b2[0] =  v[p-1][0] - b1[0];
        b1[1] = b2[1] = v[p-1][1];
        b1[2] = sd - v[p-1][1]; b2[2] = v[p-1][2] - b1[2];
      }else if(v[p-1][1] + v[p-1][2] < sd && sd < 2*v[p-1][1] + v[p-1][2]){
        //cout<<"case3"<<endl;
        b1[0] = v[p-1][0] * (sd - (v[p-1][1] + v[p-1][2])) / v[p-1][1];
        b2[0] =  v[p-1][0] - b1[0];
        b1[1] = sd - (v[p-1][1] + v[p-1][2]); b2[1] = v[p-1][1] - b1[1];
        b1[2] = b2[2] = v[p-1][2];
      }else{
        //cout<<"case4"<<endl;
        b1[0] = v[p-1][0] * (sd - (2*v[p-1][1] + v[p-1][2])) / v[p-1][2];
        b2[0] =  v[p-1][0] - b1[0];
        b1[1] = b2[1] = v[p-1][1];
        b1[2] = sd - (2*v[p-1][1] + v[p-1][2]); b2[2] = v[p-1][2] - b1[2];
      }

      if(b1[0] < b2[0]){
        v.push_back(b1);
        v.push_back(b2);
      }else{
        v.push_back(b2);
        v.push_back(b1);
      }
      v.erase(v.begin() + (p - 1) );

    }

    sort(v.begin(), v.end());
    for(int i=0; i<(int)v.size(); i++){
      cout<<v[i][0];
      if(i != (int)v.size() - 1) cout<<" ";
    }
    cout<<endl;

  }

  return 0;
}
