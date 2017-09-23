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

/*==================================================*/

/*==================================================*/

int H,W;
string a;

int alp[26];

int main() {
    cin>>H>>W;
    REP(i,0,H){
        cin>>a;
        REP(j,0,a.size()){
            alp[a[j]-'a']++;
        }
    }

    for(int i = 0; i < H/2; i++){
        for(int j = 0; j < W/2; j++){
            sort(alp,alp+26);

            if(alp[25] >= 4){
                alp[25] -= 4;
            }else{
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    if(H % 2 == 1){
        REP(j,0,W/2){
            sort(alp,alp+26);
            if(alp[25] >= 2){
                alp[25] -= 2;
                continue;
            }else{
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    if(W % 2 == 1){
        REP(i,0,H/2){
            sort(alp,alp+26);
            if(alp[25] >= 2){
                alp[25] -= 2;
                continue;
            }else{
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    if(H % 2 == 1 && W % 2 == 1){
        sort(alp,alp+26);
        if(alp[25] != 1){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;

    return 0;
}
