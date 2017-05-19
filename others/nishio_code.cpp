/*
＜ポイント＞
・'['が出るたびにvectorを作る、再帰したものをプッシュ
・数値が出るたびに今のvectorにpush
・上記２つの処理が終わったら、
　今のvectorの過半数合計値をreturn
・']'は基本無視だけど調整が必要
　（hdiをインクリメントしないので、実質"]"のタイミングで合計値処理やってる）
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<S<<endl
using namespace std;

string hds;
int hdi;

int hdfs(){
	vector<int> vt;
	int ret=0;
	if(isdigit(hds[hdi])){
		int a=0;
		while(isdigit(hds[hdi]))	a=10*a+(hds[hdi++] - '0');
		vt.push_back(a/2+1);
	}else	{
		while(hds[hdi++] == '[')	{  //この場合の"hdi++"はwhile文を抜けてからインクリメントされる。
			vt.push_back(hdfs());
			if(hds[hdi + 1] != ']') hdi++; //実際に"hdi++"でインクリメントすることはしない。
		}
	}

	sort(vt.begin(),vt.end());	//その時のレベルのvectorにすべて足してくれる。
	REP(j,0,(int)vt.size()/2+1)	ret+=vt[j];

	return ret;
}

int main(){
	int n;
	cin>>n;
	REP(i,0,n)	{
		hdi=0;
		cin>>hds;
		p(hdfs());
	}
	return 0;
}
