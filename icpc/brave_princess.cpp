/*
2017_05_09_AC
<point>
・＜ノード番号、残金＞を状態として、ダイクストラする。
・遷移先は最低一つは確実に存在する（どれだけ襲われても制約はないから、支払いなしの選択肢がある）、
　お金があるのなら、護衛を付ける場合の遷移先がもう一つある。
<caution>
・最後に min_element() で最小値を取得する際、L円まで必要なので、
　指定する範囲は、いつもより＋１大きい。
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

using namespace std;

const int INF = 1e9;

int N,M,L;
pair<int,int> road[110][110];  //＜距離、人数＞
int dp[110][110];  //d[i][j]:ノードi,残り所持金jのときの、ここまで襲われた最小人数

int main() {
  while(1){
    cin>>N>>M>>L;
    if(N==0&&M==L&&L==0) break;
    REP(i,0,N)REP(j,0,N)road[i][j]=make_pair(INF,INF);
    REP(i,0,M){
      int a,b,d,e;
      cin>>a>>b>>d>>e;
      road[a-1][b-1] = make_pair(d,e);
      road[b-1][a-1] = make_pair(d,e);
    }

    REP(i,0,N)REP(j,0,L+1) dp[i][j] = INF;

    priority_queue< pair< int ,pair<int,int> > > PQ; //人数、<ノード番号、残金>
    PQ.push(make_pair(0,make_pair(0,L)));
    dp[0][L] = 0;

    while(!PQ.empty()){
      int nowNode = PQ.top().S.F;
      int nowMoney = PQ.top().S.S;
      int nowPeople = (-1)*PQ.top().F;
      PQ.pop();

      if(dp[nowNode][nowMoney] < nowPeople) continue;
      REP(nextNode,0,N){
        if(road[nowNode][nextNode].F == INF) continue;
        int nextMoney;
        int nextPeople;
        if(road[nowNode][nextNode].F <= nowMoney){
          nextMoney = nowMoney - road[nowNode][nextNode].F;
          nextPeople = nowPeople;
          if(dp[nextNode][nextMoney] > nextPeople){
            dp[nextNode][nextMoney] = nextPeople;
            PQ.push(make_pair((-1)*dp[nextNode][nextMoney], make_pair(nextNode,nextMoney)));
          }
        }
        nextMoney = nowMoney;
        nextPeople = nowPeople + road[nowNode][nextNode].S;
        if(dp[nextNode][nextMoney] > nextPeople){
          dp[nextNode][nextMoney] = nextPeople;
          PQ.push(make_pair((-1)*dp[nextNode][nextMoney], make_pair(nextNode,nextMoney)));
        }
      }
    }
    cout<<*min_element(dp[N-1],dp[N-1]+L+1)<<endl;
  }

  return 0;
}
