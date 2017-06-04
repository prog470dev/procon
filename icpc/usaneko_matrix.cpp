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
#define REP(i,n,N) for(int i=(n);i<(int)N;i++)
#define p(s) cout<<(s)<<endl
#define ck(n,a,b) ((a)<=(n)&&(n)<(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const int inf=1e9;
int card[100010];
int usa_row[510], usa_col[510], usa_d, usa_u, usa_line;
int neko_row[510], neko_col[510], neko_d, neko_u, neko_line;
int main() {
    int n, u, v, m;

    map<int, pair<int, int> > usa_map, neko_map;
    set<int> usa_s, neko_s;

    cin>>n>>u>>v>>m;
    REP(i, 0, n){
        REP(j, 0, n){
            int usa;
            cin>>usa;
            usa_s.insert(usa);
            usa_map[usa]=(make_pair(i, j));
        }
    }
    REP(i, 0, n){
        REP(j, 0, n){
            int neko;
            cin>>neko;
            neko_s.insert(neko);
            neko_map[neko]=(make_pair(i, j));
        }
    }
    REP(i, 0, m){
        cin>>card[i];
    }

    if(n==1){
      REP(i,0,m){
        if((usa_s.find(card[i]) != usa_s.end() && u <= 1)
            && (neko_s.find(card[i]) != neko_s.end() && v <= 1)){
              cout<<"DRAW"<<endl;
              return 0;
        }else if(usa_s.find(card[i]) != usa_s.end() && u <= 1){
          cout<<"USAGI"<<endl;
          return 0;
        }else if(neko_s.find(card[i]) != neko_s.end() && v <= 1){
          cout<<"NEKO"<<endl;
          return 0;
        }
      }
      cout<<"DRAW"<<endl;
      return 0;
    }

    REP(k, 0, m){
        int num=card[k];
        // usa
        if(usa_s.find(num)!=usa_s.end()) {
            int i=usa_map[num].first;
            int j=usa_map[num].second;

            usa_row[i]++;
            usa_col[j]++;
            if(i==j) usa_d++;
            if(i+j==n-1) usa_u++;

            if(usa_row[i]==n) usa_line++;
            if(usa_col[j]==n) usa_line++;
            if(usa_d==n) {
                usa_line++;
                usa_d=0;
            }
            if(usa_u==n) {
                usa_line++;
                usa_u=0;
            }
        }

        //neko
        if(neko_s.find(num)!=neko_s.end()){
            int i=neko_map[num].first;
            int j=neko_map[num].second;
            neko_row[i]++;
            neko_col[j]++;
            if(i==j) neko_d++;
            if(i+j==n-1) neko_u++;

            if(neko_row[i]==n) neko_line++;
            if(neko_col[j]==n) neko_line++;
            if(neko_d==n) {
                neko_line++;
                neko_d=0;
            }
            if(neko_u==n){
                neko_line++;
                neko_u=0;
            }
        }
        if(usa_line>=u && neko_line>=v){
            cout<<"DRAW"<<endl;
            return 0;
        }
        else if(usa_line>=u){
            cout<<"USAGI"<<endl;
            return 0;
        }
        else if(neko_line>=v){
            cout<<"NEKO"<<endl;
            return 0;
        }
    }
    cout<<"DRAW"<<endl;


    return 0;
}
