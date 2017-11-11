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
#include <deque>
#include <algorithm>

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long  LLINF = 1e18;

using namespace std;

ll N, K;
vector<ll> A;
set<ll> s;

int main(){
  cin>>N>>K;
  REP(i,0,N) {
    ll t;
    cin>>t;
    A.push_back(t);
    s.insert(t);
  }

  sort(A.begin(), A.end());

  while(1){
    
  }

/*
  if(s.find(K) != s.end()){
    cout<<"POSSIBLE"<<endl;
    return 0;
  }
  if(A[A.size()-1] < K || A.size() == 1){
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
  }
  if(s.find(1) != s.end()){
    cout<<"POSSIBLE"<<endl;
    return 0;
  }


  bool flag = false;
  ll diff = A[1] - A[0];
  if(diff == K || diff == 1 || diff - A[0] == K || diff - A[0] == 1){
    cout<<"POSSIBLE"<<endl;
    return 0;
  }
  REP(i,2,N){
    if(A[i]-A[i-1] != diff || A[i]-A[i-1] == 1 ||
       (A[i]-A[i-1])-A[i-1] == 1 || (A[i]-A[i-1])-A[i-1] == K){
      cout<<"POSSIBLE"<<endl;
      return 0;
    }
  }

  cout<<"IMPOSSIBLE"<<endl;
*/
  return 0;
}
