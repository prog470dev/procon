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

vector<int> edge[100005];

long long N,M;
int A,B;

/*==================================================*/
/*==================================================*/

int color[100005];
long long cnt[2];
bool flag;

int check(int node, int nowcol){
    color[node] = nowcol;
    cnt[nowcol]++;

    long long ret = 1;
    REP(i,0,edge[node].size()){
        if(color[edge[node][i]] == -1){
            ret += check(edge[node][i], (nowcol+1)%2);
        }
        if(color[edge[node][i]] == nowcol){
            //ret -= 1000000000000000000;
            flag = true;
        }
    }
    return ret;
}

int main() {
    cin>>N>>M;
    REP(i,0,M){
        cin>>A>>B;
        A--; B--;
        edge[A].push_back(B);
        edge[B].push_back(A);
    }

    REP(i,0,N) color[i] = -1;

    long long ans = 0;
    if(check(0, 0) == N && !flag){
        //cout<<"T"<<endl;
        ans = cnt[0]*cnt[1] - M;
    }else{
        //cout<<"F"<<endl;
        ans = N*(N-1)/2 - M;
    }

    cout<<ans<<endl;

    return 0;
}
