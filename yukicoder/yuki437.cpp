#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

string N;

int dfs(set<int> ss, int sc){

  int ans = sc;

  for(int i=0; i<N.size(); i++){
    for(int j=i+1; j<N.size(); j++){
      for(int k=j+1; k<N.size(); k++){

        set<int> tss = ss;

        if(ss.find(i) != ss.end() || ss.find(j) != ss.end() || ss.find(k) != ss.end()) continue;
        if(N[i]!= '0' && N[j]==N[k] && N[i] != N[j]){
          tss.insert(i); tss.insert(j); tss.insert(k);
          int add = 100*(N[i] - '0') + 10*(N[j] - '0') + (N[k] - '0');
          //それぞれの適合パターンについて再帰的に最後まで計算して、その中でもっとも大きいものを選ぶ
          ans = max(ans, dfs(tss, sc + add));
        }

      }
    }
  }
  return ans;
}

int main() {

  cin>>N;
  set<int> s;

  cout<<dfs(s, 0)<<endl;

  return 0;
}
