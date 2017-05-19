/*
2017_02_24_AC
（疑問）
・newしまくっているのに、deleteせずに大丈夫なのか？
・子供の構造体をソートする方法ある？
（ポイント）
・はじめにrootとしてノードを予め作っているので、インデックスは0でなく1から始める。
・'['によりノードを作る処理があるので、葉の数値を作成するときはノード作成なし。
　currentNodeのnumとする。ひとまずここではcurrentNodeは更新しない。
　なぜなら、すぐ次の']'で更新されるから。
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

struct Node{
  int num;
  Node *parent;
  vector<Node*> children;
  Node(int num_, Node *parent_){
    num = num_;
    parent = parent_;
  }
};

int main() {
  int n;
  cin>>n;

  for(int i=0; i<n; i++){
    string s;
    cin>>s;

    Node *root = new Node(-1, NULL);  //rootの生成
    Node *currentNode = root;

    for(int j=1; j<s.size(); j++){  //数値のとき
      if(isdigit(s[j])){
        int num = 0;
        while(1){
          num = (10 * num) + (s[j] - '0');
          if(s[j+1] == ']') break;
          j++;
        }
        currentNode->num = (num/2)+1;
      }else{  //'[' or ']'
        if(s[j] == '['){
          Node *nd = new Node(-1, currentNode);
          currentNode->children.push_back(nd);
          currentNode = nd;
        }else if(s[j] == ']'){

          int sum = 0;  //注目ノードに設定する数字

          if(currentNode->children.size() > 0){ //子供あり
            vector<int> v;  //ソート用のvectorを生成
            for(int k=0; k<currentNode->children.size(); k++){
              v.push_back(currentNode->children[k]->num);
            }
            sort(v.begin(), v.end());
            for(int k=0; k<(v.size())/2 + 1; k++){
              sum += v[k];
            }
          }else{  //子供なし
            sum = currentNode->num;
          }

          currentNode->num = sum;
          currentNode = currentNode->parent;
        }
      }
    }
    cout<<root->num<<endl;
    //(?)ここで木をすべてdeleteしたい
  }

  return 0;
}
