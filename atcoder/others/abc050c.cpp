#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

long long MOD = 1000000007;


int main() {

  int N, A[100005];
  cin>>N;
  for(int i=0; i<N; i++) cin>>A[i];

  /*Original Solution*/
  /*
  int m[100005];
  fill(m, m+N, 0);

  for(int i=0; i<N; i++){
    m[(N-1)/2 - A[i]/2]++;
    if((N-1)/2 - A[i]/2 != (N-1)/2 + A[i]/2) m[(N-1)/2 + A[i]/2]++;
  }

  long long ans = 1;
  for(int i=0; i<=(N-1)/2; i++){
    if(m[i] == 0 || m[i]> 2 || (i == N/2 && m[i] >1)){
      cout<<0<<endl;
      return 0;
    }
    if(i == N/2) ans = ans;
    else ans = (ans % MOD) * 2 % MOD;
  }
  cout<<ans % MOD<<endl;
  */


  sort(A, A+N);
  int BE[100005], BO[100005], cnt;
  cnt = 0;
  for(int i=1; i<=N-1; i += 2){
    BE[cnt] = i;
    BE[cnt+1] = i;
    cnt+=2;
  }
  cnt = 1;
  BO[0] = 0;
  for(int i=2; i<=N-1; i += 2){
    BO[cnt] = i;
    BO[cnt+1] = i;
    cnt+=2;
  }

  /*Assumption Solution*/
  if(N % 2 == 0){
    for(int i = 0; i < N; i++){
      if(A[i] != BE[i]){
        cout<<"0"<<endl;
        return 0;
      }
    }
  }else{
    for(int i = 0; i < N; i++){
      if(A[i] != BO[i]){
        cout<<"0"<<endl;
        return 0;
      }
    }
  }

  long long ans = 1;
  for(int i=1; i<=N/2; i++) ans = ans * 2 % MOD;
  cout<<ans % MOD<<endl;

  return 0;
}
