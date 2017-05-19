/*
2017_05_13_AC
<point>
・素数と計算量、そしてメモリ空間使用量
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int N, P;
bool flag[102000];  /*100000より大きい素数で１００番目はこのくらい*/
vector<int> v;

int main() {
  REP(i,0,102000) flag[i] = true;
  for(int i = 2; i<102000; i++){
    if(!flag[i]) continue;
    v.push_back(i);
    for(int j = i*2; j<102000; j += i){
      flag[j] = false;
    }
  }

  while(1){
    cin>>N>>P;
    if(N==-1&&P==-1) break;
    int pos;
    REP(i,0,v.size()){
      if(N < v[i]){
        pos = i;
        break;
      }
    }
    vector<int> tv, nums;
    int cnt = 0;
    REP(i,pos,v.size()){
      if(cnt==100) break;
      tv.push_back(v[i]);
      cnt++;  /*新しい素数が、加算候補に入るので、
                少なくとも１つは新しい和の数ができる*/
      REP(j,0,tv.size()){
        nums.push_back(v[i]+tv[j]);
      }
    }
    sort(nums.begin(),nums.end());
    cout<<nums[P-1]<<endl;
  }

  return 0;
}
