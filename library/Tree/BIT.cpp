/*
Binary Indexed Tree (BIT)
変更・答えのクエリが多いときに有効

	add:  aの要素をwに更新する O(log N)
	sum:  aの合計を返す		   O(log N)

※添え字に注意
*/


--------------------------------------
//添え字1からN

int N;
int bit[1000010];

void add(int a, int w) {//aをwにする
	for (int x = a; x <= N; x += x & -x) bit[x] += w;
}

int sum(int a) {//aの合計を返す
	int ret = 0;
	for (int x = a; x > 0; x -= x & -x) ret += bit[x];
 	return ret;
}

--------------------------------------
//添え字0からN-1

int N;
int bit[1000010];

void add(int a, int w) {
	for (int x = a; x < N; x |= x + 1) 	bit[x] += w;
}

int sum(int a) {
	int ret = 0;
	for (int x = a - 1; x >= 0; x = (x & (x + 1)) - 1) {
	ret += bit[x];
 	return ret;
}

--------------------------------------
//二次元のBIT
//添え字1からN

int N;
int bit[1010][1010];

void add(int a, int b, int w){//bit[a][b]をwにする
	for (int x = a; x <= M; x += x & -x)
		for (int y = b; y <= N; y += y & -y)
			bit[x][y] += w;
}

int sum(int a, int b){
	int ret = 0;
	for (int x = a; x > 0; x -= x & -x)
		for (int y = b; y > 0; y -= y & -y)
			ret += bit[x][y];
	return ret;
}

/*==================================================*/
int main(){
	
	return 0;
}