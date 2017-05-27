#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second
#define ll long long;

const int INF = 1e9;
const long long  LLINF = 1e15;

using namespace std;

string s;
//bool exist[26];
string check[20];

int main() {
  while (1) {
      cin>>s;
      if(s == "#") break;
      REP(i,1,s.size()+1) check[i-1] = s.substr(0,i);
      //char top1 = 'a', bottom1 = 'z';
      //REP(i,0,s.size()){
      //  top1 = max(top1, s[i]);
      //  bottom1 = min(bottom1, s[i]);
      //}
      //cout<<"top1: "<<top1<<", bottom1: "<<bottom1<<endl;
      vector<string> v;
      REP(mask,0,(1<<s.size())){
        //REP(i,0,26) exist[i] = false;
        string ts = s;
        //char top2 = 'a', bottom2 = 'z';
        REP(i,0,s.size()){
          if((1<<i)&mask && ts[i]!='z'){
            ts[i]++;
          }
          //exist[ts[i] - 'a'] = true;
          //top2 = max(top2, ts[i]);
          //bottom2 = min(bottom2, ts[i]);
        }
        //cout<<"top2: "<<top2<<", bottom2: "<<bottom2<<endl;
        //if(top1 < top2 - 1 || bottom1 < bottom2 - 1) continue;
        string tmp = ts;
        //bool flag[20];
        bool stop = false;
        //REP(i,0,ts.size()) flag[i]=true;
        string checks = ts;
        for(char c='b'; c<='z'; c++){
          //if(!exist[c - 'a']) continue;
          REP(i,0,ts.size()){
            if(ts[i]==c /*&& flag[i]*/){
              //exist[ts[i] - 'a'] = false;
              ts[i]--;
              //exist[ts[i] - 'a'] = true;
              //flag[i] = false;
              if(check[i] != ts.substr(0,i+1)) stop = true;
              break;
            }
          }
          if(stop) break;
        }
        if(ts == s) v.push_back(tmp);
      }
      sort(v.begin(),v.end());
      cout<<v.size()<<endl;
      if(v.size() <= 10){
        REP(i,0,v.size()) cout<<v[i]<<endl;
      }else{
        REP(i,0,5) cout<<v[i]<<endl;
        REP(i,v.size()-5,v.size()) cout<<v[i]<<endl;
      }
  }
  return 0;
}
