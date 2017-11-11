/*
# 座圧
# 座圧座標作成時の注意
  * もとの座標を保存しておく必要がある。
  * サンプルケースはたまたま上手くいっただけ。
*/

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

int N, K;
vector<long long> x;
vector<long long> y;

/*==================================================*/
/*==================================================*/

int main() {
    cin>>N>>K;
    REP(i,0,N){
        long long a, b;
        cin>>a>>b;
        x.push_back(a);
        y.push_back(b);
    }

    //座圧
    vector<long long> vx = x;
    sort(vx.begin(), vx.end());
    vx.erase( unique(vx.begin(), vx.end()), vx.end() );
    map<long long,int> zipx; //zip[k] : ものとの座標kの圧縮座標
    map<int,long long> unzipx; //unzip[l] : 圧縮座標lのもとの座標
    REP( i, 0, vx.size() ){
      zipx[ vx[i] ] = i;
      unzipx[i] = vx[i];
    }
    vector<long long> vy = y;
    sort(vy.begin(), vy.end());
    vy.erase( unique(vy.begin(), vy.end()), vy.end() );
    map<long long,int> zipy; //zip[k] : ものとの座標kの圧縮座標
    map<int,long long> unzipy; //unzip[l] : 圧縮座標lのもとの座標
    REP( i, 0, vy.size() ){
      zipy[ vy[i] ] = i;
      unzipy[i] = vy[i];
    }

    long long ans = 4000000000000000005;

    REP(ii,0,zipx.size()){
        REP(jj,0,zipy.size()){
            REP(i,ii,zipx.size()){
                REP(j,jj,zipy.size()){
                    int cnt = 0;
                    REP(k,0,N){
                        if(ii <= zipx[x[k]] && zipx[x[k]] <= i && jj <= zipy[y[k]] && zipy[y[k]] <= j){
                            cnt++;
                        }
                    }
                    if(cnt >= K){
                        long long lx, ly;
                        lx = max(1LL, (unzipx[i] - unzipx[ii]));
                        ly = max(1LL, (unzipy[j] - unzipy[jj]));
                        ans = min(ans, lx*ly);
                    }
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
