/**
 * ワーシャル・フロイド法
 *  - 時間計算量
 *      - O( |V|^3 )
 *  - 探索対象
 *      - グラフ (vector)
 *  - MEMO
 *      - WF実行後、自分自身へのパスが一つでも負になっていれば、負の経路が存在
*/

#include <iostream>
#include <vector>
#include <queue>

#define REP(i, a, b) for (int i = a; i < b; i++)

using namespace std;

const int INF = 1e9;
const int NODE_SIZE = 1010;

int N;  //グラフのノードの数
int d[NODE_SIZE][NODE_SIZE];  //ノード接続関係 兼 最短距離(任意の二点間)  

bool negCloCir = false; //負の閉路があるかどうかのフラグ

/*==================================================*/

//ワーシャル・フロイド法
void warshall_floyd(){
    REP(k,0,N){
        REP(i,0,N){
            if(d[i][k] == INF) continue;
            REP(j,0,N){
            if(d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    REP(i,0,N){
        if(d[i][i] < 0) negCloCir = true;   //負の閉路が存在
    }
}

/*==================================================*/
int main(){
    
    REP(i,0,N){
        REP(j,0,N){
            if(i==j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    //ここでグラフの作成
    warshall_floyd();

    if(negCloCir){
        //負の閉路がある場合の処理
    }

    return 0;
}