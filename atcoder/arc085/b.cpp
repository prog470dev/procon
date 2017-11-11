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

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int dy8[] = {0,1,1,1,0,-1,-1,-1};
int dx8[] = {1,1,0,-1,-1,-1,0,1};

int N, Z, W;
int a[2005];

/*==================================================*/

/*==================================================*/

void subSolv(){
    if(N > 1){
        cout<<max(abs(a[N-1]-W), abs(a[N-2]-a[N-1]))<<endl;
    }else{
        cout<<abs(a[0]-W)<<endl;
    }
}

int dp[2005][2];

int game(int id, int player, int x, int y){
    if(id == N) return abs(x-y);

    if(dp[id][player] > -1) return dp[id][player];

    if(player == 0){ //x
        int xScore = -1;
        REP(i,id,N){
            xScore = max(xScore, game(i+1,1,a[i],y));
        }
        return dp[id][player] = xScore;
    }else{
        int yScore = INF;
        REP(i,id,N){
            yScore = min(yScore, game(i+1,0,x,a[i]));
        }
        return dp[id][player] = yScore;
    }
}


int main() {
    cin>>N>>Z>>W;
    REP(i,0,N) cin>>a[i];
    REP(i,0,N)REP(j,0,2) dp[i][j] = -1;
    cout<<game(0,0,Z,W)<<endl;
    //subSolv();
    return 0;
}
