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
#include <utility>

#define CK(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long  LLINF = 1e18;

using namespace std;


/*==================================================*/

/*==================================================*/

int N;
long long T[100005], A[100005];

const long long MOD = 1000000007;

int main(){
  cin>>N;
  REP(i,0,N) cin>>T[i];
  REP(i,0,N) cin>>A[i];

  //矛盾の確認
  for(int i = N-1; 0 <= i; i--){
    if(i < N-1){
      if(A[i] > T[i] && A[i] > A[i+1]){
        cout<<0<<endl;
        return 0;
      }
    }
    if(i == N-1){
      if(A[i] > T[i]){
        cout<<0<<endl;
        return 0;
      }
    }

    //例外
    if(i > 0 && i < N-1){
      if(T[i-1] < T[i] && A[i] > A[i+1]  && A[i] != T[i]){
        cout<<0<<endl;
        return 0;
      }
    }
  }

  for(int i = 0; i<N; i++){
    if(i > 0){
      if(T[i] > A[i] && T[i] > T[i-1]){
        cout<<0<<endl;
        return 0;
      }
    }
    if(i == 0){
      if(T[i] > A[i]){
        cout<<0<<endl;
        return 0;
      }
    }

    //例外
    if(i > 0 && i < N-1){
      if(T[i-1] < T[i] && A[i] > A[i+1]  && A[i] != T[i]){
        cout<<0<<endl;
        return 0;
      }
    }
  }



  //確定した標高を決める
  bool flag[100005];
  REP(i,0,N) flag[i] = false;

  flag[0] = true;
  REP(i,1,N){
    if(T[i-1] < T[i]){
      flag[i] = true;
      //cout<<"i: "<<i<<", i+1: "<<i+1<<"@T"<<endl;
    }
  }

  flag[N-1] = true;
  for(int i = N-2; 0 <= i; i--){
    if(A[i] > A[i+1]){
      //cout<<"i: "<<i<<", i+1: "<<i+1<<"@A"<<endl;
      flag[i] = true;
    }
  }

  //答えの計算
  long long h[100005];
  REP(i,0,N) h[i] = -1;
  REP(i,0,N){
    if(flag[i]) continue;
    h[i] = min(A[i], T[i]);
  }

  long long ans = 1;
  REP(i,0,N){
    if(flag[i]) continue;
    ans = (ans * h[i]) % MOD;
  }
  //test
  //REP(i,0,N) cout<<h[i]<<" ";
  //cout<<endl;

  cout<<ans<<endl;

  return 0;
}
