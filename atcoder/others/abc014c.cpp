/*

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

  int N, A[1005];

  cin>>N;
  for(int i=0; i<N; i++) cin>>A[i];

  int l=0, ans = 1;
  set<int> s;

  for(int r=0; r<N; i++){
    while(){

    }

    if(s.find(A[r]) == s.end()){
      s.insert(A[r]);
      r++;
      ans = max(ans , r - l+ 1);
    }else{
      l++;
      s.erase(A[l]);
    }
    if(r == N-1) break;
  }

  cout<<ans<<endl;

  return 0;
}
