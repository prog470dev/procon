#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int main() {

  int N, K, A[100005], maxlen = 1000000;
  string S[100005];
  set<int> s;

  cin>>N>>K;
  REP(i,0,K) cin>>A[i], s.insert(A[i]);
  REP(i,0,N) cin>>S[i];

  REP(i,0,K) maxlen = min(maxlen, (int)S[A[i]-1].size());

  REP(p,0,maxlen+1){
    string teststr = S[A[0]-1].substr(0,p);
    bool flag1 = true, flag2 = true;

    REP(i,0,N){
      if(teststr != S[i].substr(0,p) && s.find(i+1) != s.end()){
        flag1 = false;
        break;
      }
      if(teststr == S[i].substr(0,p) && s.find(i+1) == s.end()){
        flag2 = false;
        break;
      }
    }
    if(flag1 && flag2){
      cout<<teststr<<endl;
      return 0;
    }
  }

  cout<<-1<<endl;

  return 0;
}
