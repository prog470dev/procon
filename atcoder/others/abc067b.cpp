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

int K,N;
int l[55];

int main() {
    cin>>N>>K;
    REP(i,0,N) cin>>l[i];
    sort(l,l+N);
    int sum = 0;
    REP(i,N-K,N) sum += l[i];
    cout<<sum<<endl;
    return 0;
}
