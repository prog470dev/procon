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
  bool operator <(const st &e) const{
    return num < e.num;
  }
};

//別の方法（評価関数）
bool asc(const st& left, const st& right){
	return left.num < right.num;
}


//使用例
int main(){
  st s1(23, 2);
  st s2(111, 3);
  st s3(2, 1);

  vector<st> v;
  v.push_back(s1);
  v.push_back(s2);
  v.push_back(s3);

  sort(v.begin(), v.end());
  //sort(v.begin(), v.end(),asc);

  REP(i,0,v.size()){
    cout<<v[i].side<<endl;
  }
  return 0;
}
