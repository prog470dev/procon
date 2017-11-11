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

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int dy8[] = {0,1,1,1,0,-1,-1,-1};
int dx8[] = {1,1,0,-1,-1,-1,0,1};

string SD, T;
vector<string> sv;

/*==================================================*/

/*==================================================*/

int main() {
    cin>>SD>>T;
    for(int i = SD.size()-T.size(); i >= 0; i--){
        bool flag = false;
        REP(j,0,T.size()){
            if(SD[i+j] != T[j] && SD[i+j] != '?'){
                flag = true;
                break;
            }
        }
        if(!flag){
            string tmp = "";
            REP(j,0,SD.size()){
                if(i <= j && j < i + T.size()){
                    tmp += T[j - i];
                }else if(SD[j] == '?'){
                    tmp += "a";
                }else{
                    tmp += SD[j];
                }
            }
            sv.push_back(tmp);
            continue;
        }
    }

    if(sv.size() == 0){
        cout<<"UNRESTORABLE"<<endl;
    }else{
        sort(sv.begin(), sv.end());
        cout<<sv[0]<<endl;
    }

    return 0;
}
