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
#define F first
#define S second
#define ll long long;

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

int N, mx, coeff[] = {1,10,100,1000,10000,100000,1000000,10000000};
string S[15];

vector<char> alph;
set<char> als;
map<char,bool> notZero; //charに0を割り当て不可：true

map<char,int> m;  //アルファベットに対する数字の割り当て
set<int> used;

int dfs(int alloc){
  int cnt = 0;

  if(alloc == alph.size()){
    int left = 0;
    REP(i,0,N-1){
      int tmp = 0;
      REP(j,0,S[i].size()){
        tmp += m[S[i][j]]*coeff[S[i].size()-j-1];
      }
      left += tmp;
    }
    int right = 0;
    REP(j,0,S[N-1].size()){
      right += m[S[N-1][j]]*coeff[S[N-1].size()-j-1];
    }

    if(left == right) {
      right = 0;
      REP(j,0,S[N-1].size()){
        right += m[S[N-1][j]]*coeff[S[N-1].size()-j-1];
      }
      return 1;
    }else return 0;
  }

  //v[alloc]に対して
  REP(num,0,10){  //すべての数字を試す
    if(notZero[alph[alloc]] && num==0) continue;
    if(used.find(num) != used.end()) continue;
    used.insert(num);
    m[alph[alloc]] = num;
    cnt += dfs(alloc+1);
    used.erase(num);
  }

  return cnt;
}

int main() {
  while(1){
    cin>>N;
    if(N==0) break;
    REP(i,0,N) cin>>S[i];

    alph.clear();
    als.clear();

    REP(i,0,N){
      REP(j,0,S[i].size()){
        if(als.find(S[i][j]) == als.end()){
          als.insert(S[i][j]);
          alph.push_back(S[i][j]);
          if(j==0 && S[i].size()>1) notZero[S[i][j]] = true;
          else notZero[S[i][j]] = false;
        }
      }
    }
    cout<<dfs(0)<<endl;
  }
  return 0;
}
