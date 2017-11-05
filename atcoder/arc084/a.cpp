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

int N;
vector<int> va, vb, vc;
/*==================================================*/
/*==================================================*/

int main() {
    cin>>N;
    int t;
    REP(i,0,3){
        REP(j,0,N){
            cin>>t;
            switch (i) {
                case 0:
                    va.push_back(t);
                    break;
                case 1:
                    vb.push_back(t);
                    break;
                default:
                    vc.push_back(t);
                    break;
            }
        }
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    sort(vc.begin(), vc.end());

    long long ans = 0;
    REP(i,0,N){
        long long apos = lower_bound(va.begin(), va.end(), vb[i]) - va.begin();
        long long cpos = vc.end() - upper_bound(vc.begin(), vc.end(), vb[i]);
        ans += apos * cpos;
    }

    cout<<ans<<endl;

    return 0;
}
