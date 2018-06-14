#include "bits/stdc++.h"
#define REP(i,n,N) for(int i=(n); i<(N); i++)
#define RREP(i,n,N) for(int i=(N-1); i>=n; i--)
#define CK(n,a,b) (a)<=(n)&&(n)<(b)
#define ALL(v) (v).begin(),(v).end()
#define p(s) cout<<(s)<<endl
typedef long long ll;
using namespace std;
const ll mod =1e6+7;


vector<string> rotate(vector<string> v) {
    int y = v.size(), x = v[0].size();
    vector<string> ret;
    for(int i=0;i<x;i++){
        string tmp;
        for(int j=0;j<y;j++) tmp += v[j][i];
        reverse(ALL(tmp));
        ret.push_back(tmp);
    }
    return ret;
}

vector<string> expand(vector<string> vt, int k) {
    vector<string> vs, ret;
    for(auto v:vt){
        REP(i,0,k) vs.push_back(v);
    }
    for(auto v:vs){
        string tmp;
        for(auto r:v){
            REP(i,0,k) tmp+=r;
        }
        ret.push_back(tmp);
    }
    return ret;
}

int R,K,H,W;

int main(){
    while(cin>>R>>K>>H>>W){//R:回転(0,90,180,270), K:拡大
        vector<string> vt, ans;
        string s;

        REP(i,0,H){
            cin>>s;
            vt.push_back(s);
        }

        REP(i,0,(R%360)/90){//時計回りに90度ずつ回転
            vt = rotate(vt);
        }
        ans = expand(vt, K);//Kは拡大の倍率
        for(auto a:ans){
            p(a);
        }
    }

}