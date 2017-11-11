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

int dy[] = {0,1,1,1,0,-1,-1,-1};
int dx[] = {1,1,0,-1,-1,-1,0,1};

int N, M;
string field[50];

/*==================================================*/

/*==================================================*/

int main() {
    cin>>N>>M;
    REP(i,0,N){
        cin>>field[i];
    }

    REP(i,0,N){
        REP(j,0,M){
            if(field[i][j] == '#') continue;
            int cnt = 0;
            REP(k,0,8){
                int y = i + dy[k];
                int x = j + dx[k];
                if(!CK(y,0,N) || !CK(x,0,M)) continue;
                if(field[y][x] == '#') cnt++;
            }
            field[i][j] = (char)('0' + cnt);
        }
    }


    REP(i,0,N){
        cout<<field[i]<<endl;;
    }

    return 0;
}
