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

int main() {

  while(1){
    int N;
    cin>>N;
    if(N==0) break;
    int M, t;
    set<int> s[105];
    REP(i,1,N+1){
      cin>>M;
      REP(j,0,M){
        cin>>t;
        s[i].insert(t);
      }
    }
    int K;
    set<int> chs;
    cin>>K;
    REP(i,0,K){
      cin>>t;
      chs.insert(t);
    }

    int cnt=0, ans;
    REP(i,1,N+1){
      bool flag = true;
      set<int>::iterator it = chs.begin();
      while(it != chs.end()){
        if(s[i].find(*it) == s[i].end()){
          flag = false;
          break;
        }
        it++;
      }
      if(flag) cnt++, ans=i;
    }

    if(cnt == 1) cout<<ans<<endl;
    else cout<<-1<<endl;
  }

  return 0;
}
