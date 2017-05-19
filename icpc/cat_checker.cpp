/*
2017_05_12_AC
<point>
・インデックス変数はグローバル
・mが出るたびに、配列を生成し、各要素を再帰で探索する。
　その配列がCAT条件を満たせば、その配列のインデックスの範囲はCATになる。
・空文字列""の部分は、認識できないので、
　前後の'm','w','w'との関係から特定する。
<caution>
・終了条件に、インデックスがちょうどSの最後の文字の位置になっていることが必要
*/
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

using namespace std;

string s;
int ind=0;

//0:m, 1:e, 2:w, 3:cat;
int parse(){
  if(ind==s.size()) return -1;
  if(s[ind]=='e') return 1;
  if(s[ind]=='w') return 2;
  if(s[ind]=='m'){
    char c[5];
    c[0]=0;
    REP(i,1,5){
      ind++;
      c[i] = parse();
      if(i==2 && (c[0]==0&&c[1]==1&&c[2]==2)){
        return 3;
      }
      if(i==3 && ((c[0]==0&&c[1]==1&&c[2]==3&&c[3]==2) || (c[0]==0&&c[1]==3&&c[2]==1&&c[3]==2))){
        return 3;
      }
      if(i==4 && (c[0]==0&&c[1]==3&&c[2]==1&&c[3]==3&&c[4]==2)){
        return 3;
      }
    }
  }
  return -1;
}

int main() {
  cin>>s;
  if(parse() == 3 && ind==s.size()-1) cout<<"Cat"<<endl;
  else cout<<"Rabbit"<<endl;
  return 0;
}
