/*
2017_05_28_AC
<point>
・ 区別できる区間は、<(開始インデックス(0~), 終了インデックス), 値>の形式で記憶しておく。
・この区間の数は、最大(クエリの数)*2にしかならない。
　（各クエリで増える要素数：[W] 0or新要素＋１, [D] 0, [R] 0）
<caution>
・出力の形式を、性格に確認しておく。
（今回は、ケースごとに改行が必要だった。）
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
#define F first
#define S second
#define ll long long;

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

int N;
 //<(開始インデックス(0~), 終了インデックス), 値>
pair< pair<int, int>, int > disk[20005];

int main() {
  while(1){
    cin>>N;
    if(N==0) break;
    REP(i,0,20005) disk[i] = make_pair(make_pair(INF,INF), INF);
    disk[0] = make_pair(make_pair(0,1000000001), -1);  //-1:empty
    REP(i,0,N){
      string com, inp1, inp2;
      int num, len, ind;
      cin>>com;
      if(com=="W"){ /*書込み*/
        cin>>inp1>>inp2;
        num = stoi(inp1);
        len = stoi(inp2);
        REP(k,0,20005){
          if(len==0) break;
          if(disk[k].S == -1){
            int tl = disk[k].F.S-disk[k].F.F+1;
            if(len >= tl){
              disk[k].S = num;
              len -= tl;
            }else{
              //新要素追加
              int tmp = disk[k].F.F;
              disk[k].F.F = disk[k].F.F+len;
              RREP(l,k+1,20005){
                disk[l] = disk[l-1];
              }
              disk[k] = make_pair(make_pair(tmp, tmp+len-1), num);
              len = 0;
            }
          }
        }
      }else if(com=="D"){ /*削除*/
        cin>>inp1;
        num = stoi(inp1);
        REP(k,0,20005){
          if(disk[k].S==num) disk[k].S = -1;
        }
      }else{ /*読み取り*/
        cin>>inp1;
        ind = stoi(inp1);
        REP(k,0,20005){
          if(disk[k].F.F <= ind && ind <= disk[k].F.S){
            cout<<disk[k].S<<endl;
            break;
          }
        }
      }
    }
    cout<<endl;
  }
  return 0;
}
