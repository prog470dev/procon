/*
2017_05_13
<caution>
・入力ループの処理の中に重い処理を入れてしまうと、バグるっぽい？
　（でも、非同期（キュー的な）システムになっているはずだと思ってたんだけど・・・）
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

int N, candidate[26];

int main() {
  while(1){
    cin>>N;
    if(N==0) break;
    int left = N, ansNum = 0;
    char ansId;
    bool flag = false;
    REP(i,0,26) candidate[i] = 0;
    vector<int> v;
    REP(i,0,N){
      char tmp;
      cin>>tmp;
      v.push_back(tmp);
    }
    REP(i,0,v.size()){
      char tmp = v[i];
      candidate[tmp-'A']++;
      int t[26];
      REP(j,0,26) t[j]=candidate[j];
      sort(t,t+26);
      left--;
      if(t[25] > t[24]+left){
        flag = true;
        ansNum = i+1;
        REP(k,0,26){
          if(candidate[k]==t[25]){
            ansId = (char)('A'+k);
            break;
          }
        }
        break;
      }
    }
    if(flag) cout<<ansId<<" "<<ansNum<<endl;
    else cout<<"TIE"<<endl;
  }

  return 0;
}
