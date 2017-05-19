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
    string L[55];
    int P[55], A[55], B[55], C[55], D[55], E[55], F[55], S[55], M[55];
    cin>>N;
    if(N==0) break;
    REP(i,0,N){
      cin>>L[i]>>P[i]>>A[i]>>B[i]>>C[i]>>D[i]>>E[i]>>F[i]>>S[i]>>M[i];
    }
    vector< pair<double,string> > v;
    REP(i,0,N){
        int t = A[i]+B[i]+C[i]+ (D[i]+E[i])*M[i];
        int p = (F[i]*S[i])*M[i] - P[i];
        v.push_back(make_pair((double)p/(double)t,L[i]));
    }
    sort(v.begin(), v.end());

    RREP(i,0,v.size()){
      vector<string> sv;
      sv.push_back(v[i].second);
      if(i > 0){
        while(v[i].first == v[i-1].first){
          sv.push_back(v[i-1].second);
          i--;
          if(i == 0) break;
        }
      }
      sort(sv.begin(), sv.end());
      REP(j,0,sv.size()){
        cout<<sv[j]<<endl;
      }
    }
    cout<<"#"<<endl;
  }
  return 0;
}
