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
	int N,sum=0,count=0;
	cin>>N;
	int p[N];

	for(int i=0;i<N;i++){
		cin>>p[i];
		sum+=p[i];
	}
	bool dp[sum+1][101];
	fill(dp[0],dp[sum+1],false);

	dp[p[0]][0]=true;
	dp[0][0]=true;
	for(int i=0;i<=sum;i++){
		for(int j=1;j<N;j++){
			if(dp[i][j-1]==true || (i>=p[j]&&dp[i-p[j]][j-1]==true)){
				dp[i][j]=true;
			}
		}
	}
	for(int i=0;i<=sum;i++){
		if(dp[i][N-1]==true){
			count++;
		}
	}

	cout<<count<<endl;
	return 0;
}
