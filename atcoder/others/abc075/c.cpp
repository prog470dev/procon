#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define CK(N, A, B) (A <= N && N < B)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long LLINF = 1e18;

using namespace std;

int N, M;
bool graph[55][55];
bool visited[55];
int visitCnt;
set<pair<int, int> > st;
/*==================================================*/

/*==================================================*/

void dfs(int curNode){
    visited[curNode] = true;
    visitCnt++;
    REP(nextNode,0,N){
        if(graph[curNode][nextNode] && !visited[nextNode]){
            dfs(nextNode);
        }
    }
}

int main() {
    cin>>N>>M;
    REP(i,0,M){
        int a, b;
        cin>>a>>b;
        a--; b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    int ans = 0;

    REP(i,0,N){
        REP(j,0,N){
            if(!graph[i][j] || st.find(make_pair(i,j)) != st.end()) continue;
            else graph[i][j] = graph[j][i] = false, st.insert(make_pair(j,i));
            REP(i,0,N) visited[i] = false;
            visitCnt = 0;
            dfs(0);
            if(visitCnt != N){
                ans++;
                //cout<<i<<" -> "<<j<<endl;
            }
            graph[i][j] = graph[j][i]= true;
        }
    }

    cout<<ans<<endl;

    return 0;
}
