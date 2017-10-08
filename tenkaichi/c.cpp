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

long long N;

int main() {
    cin>>N;
    for(long long h = 1; h <= 3501; h++){
        for(long long n = 1; n <= 3501; n++){
            if(4*h*n - N*n - N*h <= 0) continue;
            if(N*h*n % (4*h*n - N*n - N*h) == 0){
                int w = N*h*n / (4*h*n - N*n - N*h);
                if(h<=0 || n<=0 || w<=0) continue;
                cout<<h<<" "<<n<<" "<<N*h*n / (4*h*n - N*n - N*h)<<endl;

                //test
                //cout<<4*h*n*w <<" == "<< N*n*w + N*h*w + N*h*n <<endl;

                return 0;
            }
        }
    }
    return 0;
}
