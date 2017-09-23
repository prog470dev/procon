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

char c[] = {'Y','A','K','I'};

int main() {

    string s;
    cin>>s;
    if(s.size() < 4){
        cout<<"No"<<endl;
        return 0;
    }
    REP(i,0,s.size()){
        if(i < 4){
            if(c[i] != s[i]){
                cout<<"No"<<endl;
                return 0;
            }
            if(i == 3){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        if(i >= 4){
            cout<<"No"<<endl;
            return 0;
        }
    }

    return 0;
}
