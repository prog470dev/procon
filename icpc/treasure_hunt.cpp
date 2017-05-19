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
#define X first
#define Y second

using namespace std;

int n, m;
vector<int> vx, vy;
int tx[5005], ty[5005], unzipx[5005], unzipy[5005], imos[5005][5005];
map<int, int> zipx, zipy;
pair< pair<int,int>, pair<int,int> > p[500005];

int main() {
  cin>>n>>m;
  REP(i,0,n){
    cin>>tx[i]>>ty[i];
    vx.push_back(tx[i]);
    vy.push_back(ty[i]);
  }
  REP(i,0,m){
    cin>>p[i].F.X>>p[i].F.Y>>p[i].S.X>>p[i].S.Y;
  }

  //compression
  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());
  //ここは消してもAC（高速化はできる）
  //vx.erase(.unique(vx.begin(), vx.end()), vx.end());
  //vy.erase(unique(vy.begin(), vy.end()), vy.end());
  REP(i,0,vx.size()){
    zipx[vx[i]] = i;
    unzipx[i] = vx[i];
  }
  REP(i,0,vy.size()){
    zipy[vy[i]] = i;
    unzipy[i] = vy[i];
  }

  //Initializing imos array
  REP(i,0,5005)REP(j,0,5005) imos[i][j] = 0;
  REP(i,0,n){
    imos[zipy[ty[i]]][zipx[tx[i]]]++;
  }
  //creating imos array
  REP(i,0,vy.size()){
    REP(j,1,vx.size()){
      imos[i][j] += imos[i][j-1];
    }
  }
  REP(j,0,vx.size()){
    REP(i,1,vy.size()){
      imos[i][j] += imos[i-1][j];
    }
  }

  REP(i,0,m){
    /*
    cout<<"xSize:"<<vx.size()<<", "<<"ySize:"<<vx.size()<<endl;
    cout<<"test: "<<(lower_bound(vx.begin(),vx.end(),p[i].F.X)-vx.begin())<<" ";
    cout<<(lower_bound(vy.begin(),vy.end(),p[i].F.Y)-vy.begin())<<" ";
    cout<<(lower_bound(vx.begin(),vx.end(),p[i].S.X)-vx.begin())<<" ";
    cout<<(lower_bound(vy.begin(),vy.end(),p[i].S.Y)-vy.begin())<<endl;
    */
    vector<int>::iterator a1x = lower_bound(vx.begin(),vx.end(),p[i].F.X),
      a1y = lower_bound(vy.begin(),vy.end(),p[i].F.Y),
      a2x = upper_bound(vx.begin(),vx.end(),p[i].S.X)-1,
      a2y = upper_bound(vy.begin(),vy.end(),p[i].S.Y)-1;
    int z1x = zipx[*a1x], z1y = zipy[*a1y], z2x = zipx[*a2x], z2y = zipy[*a2y];
    int ans = imos[z2y][z2x];
    if(z1y > 0) ans -= imos[z1y-1][z2x];
    if(z1x > 0) ans -= imos[z2y][z1x-1];
    if(z1y > 0 && z1x > 0) ans += imos[z1y-1][z1x-1];

    if(p[i].F.Y > unzipy[vy.size()-1] || p[i].F.X > unzipx[vx.size()-1]) cout<<0<<endl;
    else if(p[i].S.Y < unzipy[0] || p[i].S.X < unzipx[0]) cout<<0<<endl;
    else cout<<ans<<endl;
  }

  return 0;
}
