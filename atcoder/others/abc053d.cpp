/*
2017_01_28

「３枚取って、その中央値が残る」　→　「１回で２枚ずつ減る」
３個以上あるものは、それだけを使って２個以下にできる（偶：２個、奇：１個）
偶数のものは、２セット使用して１セットにできる

(解法手順)
１．数字でなく個数の数列にする
２．数列のすべてを１個か２個にする
３．２個のものの数が偶数なら、(odd+eve)、奇数なら（odd+eve-1）
*/

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

  int N, A[100005];

  fill(A, A+100005, 0);

  cin>>N;
  for(int i=0; i<N; i++){
    int a;
    cin>>a;
    A[a]++;
  }

  int odd = 0, eve = 0;
  for(int i = 0; i<100005; i++){
    if(A[i] == 0) continue;
    if(A[i] % 2 == 0) eve++;
    else odd++;
  }

  cout<<odd + (eve/2)*2 <<endl;

  return 0;
}
