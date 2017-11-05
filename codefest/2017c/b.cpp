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

/*==================================================*/

/*==================================================*/

long long N, A[10];

long long  ans = 1, odd = 1;

int main() {
    cin>>N;
    REP(i,0,N){
        cin>>A[i];
        if(A[i] % 2 != 0) odd *= 1;
        else odd *= 2;
        ans *= 3;
    }

    ans -= odd;

    cout<<ans<<endl;

    return 0;
}
