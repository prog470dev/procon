/*
2017_03_14_AC
＜ポイント＞
・左に注目していても、「右が動いて、左が動かない」こともある。
　＝＞
・再帰で書くとスタックオーバーフロー
＜疑問＞
・同じ深さ優先でも、再帰だと駄目で、スタックだとOKの理由。
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
#include <algorithm>
#include <stack>
#include <queue>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int ldx[] = {1,0,-1,0}, ldy[] = {0,1,0,-1};
int rdx[] = {-1,0,1,0}, rdy[] = {0,1,0,-1};

int H, W;
int slx, sly, srx, sry;
string rooml[55], roomr[55];
bool flag;

bool ls[55][55][55][55];
/*
void dfs(int lx, int ly, int rx, int ry){
	//cout<<lx<<" "<<ly<<": "<<rx<<" "<<ry<<endl;
	if(flag) return;

	if(rooml[ly][lx] == '%' && roomr[ry][rx] == '%') {
		flag = true;
		return;
	}else if(rooml[ly][lx] == '%' || roomr[ry][rx] == '%') return;

	if(ls[lx][ly][rx][ry]) return;
	ls[lx][ly][rx][ry] = true;

	REP(k,0,4){
		int nlx = lx + ldx[k], nly = ly + ldy[k];
		if(!CH(nly,0,H) || !CH(nlx,0,W)){
			nlx = lx;
			nly = ly;
		}else if(rooml[nly][nlx]=='#'){
			nlx = lx;
			nly = ly;
		}

		int nrx = rx + rdx[k], nry = ry + rdy[k];
		if(!CH(nry,0,H) || !CH(nrx,0,W)){
			nrx = rx;
			nry = ry;
		}else if(roomr[nry][nrx]=='#'){
			nrx = rx;
			nry = ry;
		}
		if(ls[nlx][nly][nrx][nry]) continue;
		dfs(nlx, nly, nrx, nry);
	}
	return;
}
*/

bool bfs(){
	queue <int> lxq;
	queue <int> lyq;
	queue <int> rxq;
	queue <int> ryq;

	lxq.push(slx);
	lyq.push(sly);
	rxq.push(srx);
	ryq.push(sry);

	while(!lxq.empty()){
		int lx = lxq.front();
		int ly = lyq.front();
		int rx = rxq.front();
		int ry = ryq.front();
		lxq.pop(); lyq.pop(); rxq.pop(); ryq.pop();
		if(rooml[ly][lx] == '%' && roomr[ry][rx] == '%') {
			//flag = true;
			return true;
		}else if(rooml[ly][lx] == '%' || roomr[ry][rx] == '%') continue;

		if(ls[lx][ly][rx][ry]) continue;
		ls[lx][ly][rx][ry] = true;

		REP(k,0,4){
			int nlx = lx + ldx[k], nly = ly + ldy[k];
			if(!CH(nly,0,H) || !CH(nlx,0,W)){
				nlx = lx;
				nly = ly;
			}else if(rooml[nly][nlx]=='#'){
				nlx = lx;
				nly = ly;
			}

			int nrx = rx + rdx[k], nry = ry + rdy[k];
			if(!CH(nry,0,H) || !CH(nrx,0,W)){
				nrx = rx;
				nry = ry;
			}else if(roomr[nry][nrx]=='#'){
				nrx = rx;
				nry = ry;
			}
			if(ls[nlx][nly][nrx][nry]) continue;
			//dfs(nlx, nly, nrx, nry);
			lxq.push(nlx); lyq.push(nly); rxq.push(nrx); ryq.push(nry);
		}
	}
	return false;
}

int main() {

	while(1){
		cin>>W>>H;
		if(W==0 && H==0) break;
		REP(i,0,H){
			cin>>rooml[i]>>roomr[i];
		}

		REP(i,0,H){
			REP(j,0,W){
				if(rooml[i][j] == 'L'){
					slx = j;
					sly = i;
				}
				if(roomr[i][j] == 'R'){
					srx = j;
					sry = i;
				}
			}
		}


		flag = false;
		REP(i,0,55)REP(j,0,55)REP(k,0,55)REP(l,0,55) ls[i][j][k][l] = false;
		/*
		dfs(slx, sly, srx, sry);
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		*/
		if(bfs())cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
  return 0;
}
