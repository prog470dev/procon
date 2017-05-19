#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {

  int n;
  bool f[55][35];

  while(1){

    memset(f, false, sizeof(f));

    cin>>n;
    if(n == 0) break;

    for(int i=0; i<n; i++){
      int t;
      cin>>t;
      if(t == 0) break;
      for(int j=0; j<t; j++){
        int tt;
        cin>>tt;
        f[i][tt] = true;
      }
    }

    set<int> s[55];
    for(int i=0; i<50; i++){
      s[i].insert(i);
    }
    int ans = 1;

    for(int day = 1; day <= 30; day++){
      set<int> v;
      for(int mem = 0; mem < n; mem++){
        if(f[mem][day]){
          set<int>::iterator it = s[mem].begin();
          while(it != s[mem].end()){
            v.insert((*it));
            it++;
          }
        }
      }

      for(int mem = 0; mem < n; mem++){
        if(f[mem][day]){
          s[mem] = v;
        }
      }
      bool flag = false;
      for(int mem = 0; mem < n; mem++){
        if(s[mem].size() == n) flag = true;
      }
      if(flag) break;
      ans++;
    }

    if(ans == 31) cout<<-1<<endl;
    else cout<<ans<<endl;

  }

  return 0;
}
