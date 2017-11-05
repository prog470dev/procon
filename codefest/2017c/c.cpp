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

string S;

/*==================================================*/
/*==================================================*/

int main() {
    cin>>S;
    string s1="", s2="";
    REP(i,0,S.size()){
        if(S[i] != 'x') s1 += S[i];
        if(S[S.size()-1-i] != 'x') s2 += S[S.size()-1-i];
    }
    if(s1 != s2){
        cout<<-1<<endl;
        return 0;
    }

    int l = -1, r = S.size();
    int ans = 0;

    //test
    int c = 0;
    while(1){
        //test
        //cout<<"l: "<<l<<", r: "<<r<<endl;
        //if(c == 10) break;
        c++;

        if(l == r || l+1 == r){
            break;
        }

        if(S[l + 1] == 'x' && S[r - 1] != 'x'){
            //cout<<"test1"<<endl;
            int t = 1;
            while(S[l + t] == 'x'){
                t++;
            }
            ans += (t - 1);
            l += t;
            r--;
        }else if(S[l + 1] != 'x' && S[r - 1] == 'x'){
            //cout<<"test2"<<endl;
            int t = 1;
            while(S[r - t] == 'x'){
                t++;
            }
            ans += (t - 1);
            r -= t;
            l++;
        }else{
            l++;
            r--;
        }
    }

    cout<<ans<<endl;

    return 0;
}
