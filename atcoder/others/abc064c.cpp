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

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long;

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

int clorlim[] = {400, 800, 1200, 1600, 2000, 2400, 2800, 3200};

int main() {
  int N;
  cin>>N;
  vector<int> v;
  REP(i,0,N){
    int tmp;
    cin>>tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());

  vector<int> tv;
  //set<int> tv;
  set<int> s;
  REP(i,0,N){
    bool flag = false;
    REP(j,0,8){
      if(v[i] < clorlim[j]){
        s.insert(j);
        flag = true;
        break;
      }
    }
    if(!flag){
      tv.push_back(v[i]);
      //tv.insert(v[i]);
    }
  }

  cout<<max(1, (int)s.size())<<" "<<s.size() + tv.size()<<endl;


  return 0;
}
