/*
構造体
概要：
  ・booloperatorで順序のルールを追加
*/
struct st{
  int num;
  int side;
  //コンストラクタ
  st(int _num, int _side){
    num = _num;
    side = _side;
  }
  bool operator >(const st &e) const{
    return num > e.num;
  }
};

//使用例
int main(){
  st s1(23, 2);
  st s2(111, 3);
  st s3(2, 1);
  vector<st> v{s1,s2,s3};
  sort(v.begin(),v.end());
  REP(i,0,v.size()){
    cout<<v[i]<<endl;
  }
  return 0;
}
