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

int N, x, y;
vector< pair<int, int> > xdist;
vector< pair<int, int> > ydist;
vector< pair< int, pair<int, int> > > edge;

/*==================================================*/
const int MAX_N = 100010;
struct UnionFind{
    int par[MAX_N];
    int deph[MAX_N];
    UnionFind(int n){
        fill(par, par + MAX_N, -1);
        for(int i=0; i<n; i++){
            par[i] = i;
            deph[i] = 0;
        }
    }
    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(deph[x] < deph[y]){
            par[x] = par[y];
        }else{
            par[y] = par[x];
            if(deph[x] == deph[y]) deph[x]++;
        }
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};
/*==================================================*/

int main() {
    cin>>N;
    REP(i,0,N){
        cin>>x>>y;
        xdist.push_back(make_pair(x, i));
        ydist.push_back(make_pair(y, i));
    }
    sort(xdist.begin(), xdist.end());
    sort(ydist.begin(), ydist.end());

    REP(i,0,N-1){
        edge.push_back(make_pair(xdist[i+1].F - xdist[i].F, make_pair(xdist[i].S, xdist[i+1].S)));
        edge.push_back(make_pair(ydist[i+1].F - ydist[i].F, make_pair(ydist[i].S, ydist[i+1].S)));
    }
    sort(edge.begin(), edge.end());

    // REP(i,0,edge.size()){
    //     cout<<edge[i].F<<": "<<edge[i].S.F<<", "<<edge[i].S.S<<endl;
    // }

    long long ans = 0;

    UnionFind uf(N);
    REP(i,0,edge.size()){
        int n0 = edge[i].S.F;
        int n1 = edge[i].S.S;
        if(!uf.same(n0, n1)){
            ans += (long long)edge[i].F;
            uf.unite(n0, n1);
        }
    }

    cout<<ans<<endl;

    return 0;
}
