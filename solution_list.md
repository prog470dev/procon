# 制約
## 最短距離 
* 重みなし

    * [幅優先探索](#幅優先探索(bfs))

        

* N<5*10^2 O(N^3)

    - [ワーシャルフロイド](#ワーシャルフロイド)

    

* |V|<=10^5 O(|V|log|E|)

    - [ダイクストラ](#ダイクストラ)

      

* |E|<=10^5, 負のループ

    * ベルマンフォード O(|E||V|)

        * 正の閉路は負の閉路にする(コストを全て負にする)

        

* 経路のルールが複数ある(運賃に距離が影響するetc)
    - 情報の書き換え(駅ごとの 距離->運賃 etc)



## ノード数N, エッジ数N-1

* 木

## Uターン禁止

- 一つ前を覚える

  

## 座標の範囲が広い
- [座圧](#座圧)

- 範囲で持つ(セルを１つ１つはチェックしない)

  

## 文字に数字を当てはめる
- 文字でまとめる

- 桁でまとめる

  

## 色塗り
- 塗られる場所ではなく, 塗るものの起点から塗る(計算量減る)

- 色がかぶることに注目

- [逆順](#逆順)でやると塗りつぶしを考えなくて良くなったりする

  

## 重なり
- imos法
  - 次元を独立に考えたり.

    

## 最大値-最小値を求める
* 最大値か最小値を固定

  

## ソート済み配列中に任意の数があるか探す(O(logN))
- (upper_bound - lower_bound) => 個数

  

## グラフ関係
- 最終的な遷移先をまとめる (前処理)

  

## 文字列比較
- ソートして隣と比較（類似度 etc）

  

## b進法
- 分母がbの分数はb進法で、有限桁数(小数点第一位まで)の小数で表せる.
- 分母bの素因数の積cとすると, (分母がbの分数は)c進法の有限桁数の小数で表せる.



## ターン毎に移動させるものが異なる（どれかかがゴールすれば良い）

- 現在地のパターンは、次の移動の制限でしかない.(現在地は１つと考える)
- 例：”崖登り”



## 市松模様

- 縦＋横の和の偶奇
- グリッドグラフは*市松模様*に塗ると二部グラフ
- 市松模様の一辺サイズがKのとき, 縦横ともに2K周期なので塗り方としては(2K x 2K)通りの塗り方を試すと十分で, 座標はmod 2K
- 累積と相性よい.



## ペアをつくるとき

* 2グループに, 片方は固定, 片方は全探索
* 二部マッチング



## 二つに分けた時の最大・最小

* 片方をxと置くと, もう一方を(N-x)と置ける. x(N-x)は二次関数である



## 括弧があるパーサ

* 開くタイミングで再帰呼び出し
* 閉じるタイミングで再帰戻る
* [参照: 括弧の対応](#括弧の対応)



## 6方向探索

* 出発点に注意((0,0)はじまりだと負になるので調整)



## 正方形の個数

* x軸で見た時の2点間の長さのヒストグラムとy軸のヒストグラムを別々に求めて同じ数の者同士をかける
* 切片で回す



## 逆順

* 逆順から考えたほうが初期状態が小さい(状態数や計算量が)



## 取り除く系

* 最大最小: [区間DP](#DP)

* 深さ優先探索

  

## 組み合わせのmod

* [DP](#DP)
* フェルマーの小定理(O(10^5))
* 式で一発(制約でわかる)



## ある数以下(または範囲)で条件を満たすものの個数or最大最小

* [桁DP](#DP)

  

## マンハッタン距離

* 45度回転(問題文に x+y とか x−yがあったらチャンス )



## チェビシェフ距離

* d = max(|x1−x2|,|y1−y2|)

* 移動回数2回で, ±dの範囲(正方形) は全部いける

  

## 距離(差)の総和の最小化

* 中央値を使うと最小になる
* 三分探索



## クエリ

* 逆から考える



## 角度

* 内積
* 余弦定理



## 面積, 体積

* どちらで求めるか吟味すること

  * 直接求める

  * 比で求める

    

## 区間

* [尺取り](#尺取り)で個数数え挙げ



 ## 〇〇以上, ◯◯以下

* [二分探索](#二分探索)を思い浮かべる

  * 答え以上or答え以下で抽象化する




## 一筆書き

* [オイラー路](#オイラー路)

## ある条件を満たす数を書き出した中でK番目に大きい数 ( O(N log N) )

* [二分探索](#二分探索)

  * ある条件: M番目に大きい数

  * x以下の数がK個以上ある最小のxを求める

    例) 1 1 4 3 2  →x以下の数が3個以上の最小のx = 2

    左側を固定してmid以下の数がMになるところをrとすると

    r以降は何を追加してもmid以下がM個以上になる

    → [尺取り法](#尺取り)が使える.

## n bitのうち, k bit 立っている数の個数とその総和

- [組み合わせ](#組み合わせ) 

- k bit立っている数の個数はnCk, 

- k bit立っている数の総和は

  (2^n-1) * n-1C(k-1)

## あみだくじ

- 逆から見れば[バブルソート](#バブルソート)O(N^2)

  

=====

# 手法
## ダイクストラ
- [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/MinimumPath/dijkstra.cpp) 

- 状態をまとめる (DPっぽさ)

- 負のコストがあると使えない

  

## ワーシャルフロイド

* [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/MinimumPath/warshall_floyd.cpp) 
* 複数回回す(いらないノードやエッジを消してもう一回)



## 幅優先探索(bfs)

* [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/Explore/bfs.cpp) 

* 前処理できるならする. (エッジの種類を変える, 状態を削減する)

* 出発点が複数あったら, それを仮ノードにつないで仮ノードから出発(エッジのコストは1, 最後に1引く)

  

チェックリスト

- [ ] 初期状態とある状態までの何を求めたい?

  迷路: スタートからある地点(ゴール)までの最短距離

  日数: スタートからあるノードまで行くのにかかる日数

- [ ] 1ステップのコストは?

  - 重みなし(1ステップ1コスト)
  - 重みあり(1ステップwコスト)

- [ ] 遷移先

  - 迷路: 4方向(dx,dy)
  - 6角形: 6方向(ただし負にならないように)
  - ノードからノード
  - 親から子(有向グラフなど)

- [ ] 枝刈り

  1. 動けないところ
     * 壁
     * 範囲外
  2. もう探索しなくていいところ
     * 一度訪れたところ
     * もうそれよりいい状態が過去にあった

- [ ] 初期化

  - スタート(1始まりだったら-1する)
  - ゴール(1始まりだったら-1する)
  - [フィールド](#フィールド問題)
  - 答えにしたい配列の初期化(最大なら-inf,最小ならinfなど)
  - 訪れたかどうか(bool visited[])



## フィールド問題

* `vector<string> field;`または`vector<vector<int>> field(N,vector<int> N);`とするとよい
  * fieldのコピーを作る時は `auto field_copy = field;`でよい



## 座圧
- [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/ProconTech/compress.cpp) 
- [２次元累積和](#累積和) 
- 手順: ソート, 重複削除
- もとの値を参照: unzipして[二分探索](#二分探索)



## 累積和

- [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/ProconTech/CumulativeSum.cpp) 
- 範囲内の重なっている数を数える



## DP

- ソートしても良さそうならDPの可能性あり(順番が関係ないということなので)
- 配列サイズに余裕がある
    * 抽象化に漏れが無いか考える (インデックス[状態の要素]の追加)
- bitDP
    - [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/DP/bitDP.cpp)
    - 2つのbitを同時に立てる時もある(ペアを作る時など)
- 木DP
    - 木構造で最大最小を求めるときに使う
    - ただのメモ化再帰
    - dfsの中でdpして最大を求めたりする. 頑張って一般化する
- 区間DP
    - [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/DP/rangeDP.cpp) 
    - dp\[L]\[R] := 区間[L.R]についての何か
    - 区間の小さい方から大きい方に回す
    - dp\[L]\[R] を　dp\[L+1]\[R-1]やdp\[L+1]\[R] + dp\[L]\[R-1]で更新する
    - 区間の区切り目で回すことを忘れない
    - 累積和との相性◎
- 桁DP
    - [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/DP/digitDP.cpp) 
    - ある数以下で条件を満たすものの個数とか最大が得意
    - A~Bまでの区間で求めたいときはB以下からA-1以下を引けば答え
    - 0~9が出るor出ないを管理するときとかに使える
    - 倍数との相性◎(mod で考える) 



## 再帰

* [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/Explore/dfs.cpp)

* メモ化はしとこう! (特に実行時間が長かったら)

* 再帰呼び出した後, 状態をもどすのを忘れない

  例: x++; 

  ​      y = dfs(x); 

  ​      x--; //戻ってきたので直す

  

## 二分探索

* [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/Explore/nibutan.cpp) 
* 片半区間でまわすとバグらない!
* 答えそのものを二分探索する



## 尺取り

* [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/ProconTech/shakutori.cpp) 
* 区間で条件を満たすものの数え挙げ
* 左を固定して右はそれ以上考えなくても良いという条件を考える




## 半分全列挙

* [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/ProconTech/half_full_enumeration.cpp) 

* O(2^(n/2))

* 2つに分割してそれぞれに対しその時点であわない物を省く

* 2つに対し[尺取り](#尺取り)する

  

## オイラー路

* 条件は2つ

  * すべてのノードが連結([UnionFind](#UnionFind))
  * 次数(ノードについてるエッジの数)が奇数の頂点の個数が0個か2個



## UnionFind

- [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/Tree/UnionFind.cpp) 
- [ライブラリ(グループ版)](https://github.com/prog470dev/procon/blob/master/library/Tree/UnionFind_QuickFindWeighted.cpp) 
- クエリに対して連結成分を作成
- O(log|V|)



## 組み合わせ

* [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/Mathematics/combination.cpp)

* nCr ： n個の中からr個選ぶときの組み合わせ数

* k bit立っている数の総和は

  (2^n-1) * n-1C(k-1)



## 分数の計算

* 分母と分子は別にする

	 次の分母の値を足す(分母 i)	sum / prod + 1 / i = (sum\*i +  prod) / prod*i

  

## 門松列

* 作り方

  1, 3, 2, 4, 1, 3, 2, 4, ...



## 括弧の対応

* stackにインデックスを積む(ただし文字列が長すぎる(|S|>10^7あたり)とスタックオーバフローする)
* '(' ならcnt+=1 , ')'ならcnt=-1していく
* 括弧の対応がただしいならcntが途中で負にならない(もしくはスタックが空のときpopしない)



## バブルソート

* O(N^2)

* swap回数を求めるだけならBITを使うとO(NlogN)

  

## mod演算

* 足し算：(A%MOD+B%MOD)%MOD 
* 引き算：(A%MOD+MOD-B%MOD)%MOD 
* かけ算：((A%MOD) * (B%MOD))%MOD
* 割り算：((A%MOD) * **modpow(B,MOD-2)**)%MOD //フェルマーの小定理
* 累乗：modpow(A,B) //指数部はmodしちゃだめ



## ある日の曜日

y 年 m 月 d 日 の曜日h

(紀元前yy年はy = 1-yyで考える(紀元前1年のときy=0))

注意) int型なので割り算は全部切り捨てです.

Y = (y+100) mod 100 (うるい年じゃない)

C = y /100 

Γ = 5C + C/4 (1582 < = y (グレゴリオ歴))

Γ = 6C + 5    (4<= y <= 1582 (なんたら歴))

とすると, 下の式になる. 

**h = { d + 26(m+1)/10 + Y + Y/4 +  Γ } mod 7**



* その他大事なこと

  * カレンダーは400年周期である

  * 4年で割れるならうるう年

    * ただし100で割れるならnotうるう年

    * ただし400で割れるならうるう年

      

# データ構造　

- [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/Other/original_struct.cpp) 
- 忘れた使い方あったら[ここ](https://www.qoosky.io/techs/5cd1a59497)がよい



## bit操作

- #### [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/Other/Technique_bit.txt) 

- #### 立っているbit数を数える(1000なら1)　 __builtin_popcountll

- #### 立っているbitの偶奇を数える(1000なら1)     __builtin_parityll

- #### 下から何桁目で初めて1が現れるか(1000なら4)    __builtin_ffsll

- #### bitのもっとも右に立っているもののみにする(1010なら0010)    bit & -bit

- #### bitのもっとも右に立っているものを0にする(1010なら1000)    bit & (bit - 1)

- ####  bitset

  - #### bitset<8> bs("00000101");

  - #### bs[0]: 1 bs[1]: 0 ....

  - #### bs.set(3) // 3ビット目を1に(00001101)

  - #### bs.reset(2) // 2ビット目を0に(00001001)

  - #### bs.any() // 立っているビットがあるかどうか

  - #### bs.all() // 全ビットが立っているか

  - #### bs.none() // 全ビットが0 

  - #### bs.count() // ビットが立っている数

  - #### bs.flip() // 全ビット反転

  - #### bs.to_string() // ビット列を文字列に

  - #### bs.to_ullong() // ビットをunsigned long long に



## unordered_map と map

* unordered_map
  * ハッシュテーブル
  * 登録,削除,検索: O(1)
  * キーは順序がないので注意



* map
  * 二分木
  * 登録,削除,検索: O(log N)
  * キーの順序が関係ないならunordered_mapを使う



## string

* [ライブラリ](https://github.com/prog470dev/procon/blob/master/library/Other/string_memo.txt)



* 1行読み込み cin.ignore(); getline(cin,s)   (cin.ignore()は1回のみ呼び出せば良い)



* 挿入: str.insert(pos, string) または str.insert(pos, 数, char)

  