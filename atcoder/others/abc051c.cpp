#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {

  int sx, sy, tx, ty;
  cin>>sx>>sy>>tx>>ty;

  int dy = ty - sy, dx = tx - sx;

  //cout<<"dx:"<<dx<<" "<<"dy:"<<dy<<endl;

  for(int i=0; i<dx; i++)cout<<"R";
  for(int i=0; i<dy; i++)cout<<"U";
  for(int i=0; i<dx; i++)cout<<"L";
  for(int i=0; i<dy; i++)cout<<"D";
  cout<<"L";
  for(int i=0; i<dy+1; i++)cout<<"U";
  for(int i=0; i<dx+1; i++)cout<<"R";
  cout<<"DR";
  for(int i=0; i<dy+1; i++)cout<<"D";
  for(int i=0; i<dx+1; i++)cout<<"L";
  cout<<"U"<<endl;

  return 0;
}
