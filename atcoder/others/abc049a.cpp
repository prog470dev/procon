#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {

  string s;
  cin>>s;
  if(s =="a" || s =="i" || s =="u" || s =="e" || s =="o"){
    cout<<"vowel"<<endl;
  }else{
    cout<<"consonant"<<endl;
  }

  return 0;
}
