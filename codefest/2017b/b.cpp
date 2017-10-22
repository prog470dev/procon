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

int N, D, M, T;
map<int,int> m;

int main() {
    cin>>N;
    REP(i,0,N){
        cin>>D;
        m[D]++;
    }
    cin>>M;
    REP(i,0,M){
        cin>>T;
        if(m.find(T) != m.end()){
            m[T]--;
            if(m[T] < 0){
                cout<<"NO"<<endl;
                return 0;
            }
        }else{
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;

    return 0;
}
