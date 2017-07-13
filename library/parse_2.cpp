/*
 [階層制主義]
 ・「囲む」ための左端トークンに出会うたびに、
 　新しいオブジェクトを生成し、そこでいちからスタート。
 */

int N;
string S;

int ind;
int parse(){
    int ret = 0;
    if(S[ind] == '['){
        vector<int> v;
        ind++;
        while(S[ind]!=']') v.push_back(parse());
        ind++;
        sort(v.begin(),v.end());
        REP(i,0,v.size()/2+1) ret += v[i];
    }else if(isdigit(S[ind])){
        while(isdigit(S[ind])){
            ret = 10*ret + (int)(S[ind] - '0');
            ind++;
        }
        ret = ret/2 + 1;
    }
    return ret;
}

int main(){
    cin>>N;
    REP(i,0,N){
        cin>>S;
        ind=0;
        cout<<parse()<<endl;
    }
    return 0;
}


/**************************************************************************/


/*
 [Cat_Checker]
 ・文法に合っているかのチェック系
 ・「文法に合わない」なら再帰呼び出し、が基本の流れ。
 ・終了位置のポインタを返す。
 ・関数の引数としてポインタを渡しているが、その関数の返り値もポインタの値であるため、
 　グローバル変数でなくても、ポインタの値は更新される。
 */

string S;
int parse(int p){
    if(S.size() <= p){
        return -1;
    }
    
    if(S[p] != 'm'){
        /*
         *パース対象の先頭は'm'である必要がある。
         *（pが進まずそうしなければ無限ループに入る）
         */
        return -1;
    }
    p++;
    if(S[p] != 'e'){
        p = parse(p);
        if(p==-1 || p >= S.size()) return -1;
    }
    p++;
    if(S[p] != 'w'){
        p = parse(p);
        if(p==-1 || p >= S.size()) return -1;
    }
    /*
     *ここでもインクリメントしないと
     *再帰呼び出しの位置に戻ったときに次の文字を読み込めない
     */
    p++;
    return p;
}

int main(){
    cin>>S;
    int t = parse(0);
    if(t == S.size()) cout<<"Cat"<<endl;
    else cout<<"Rabbit"<<endl;
    
    return 0;
}


/**************************************************************************/


/*
 [壊れた暗号生成器]
 ・文字列変換系。
 ・どうしても上手く作れなかったら、更新する文字列とポインタはグローバルに設定。
 */


string S;
string ans;
int p=0;
void parse(int cnt){
    if(p==S.size()) return;
    if(S[p] == '['){
        p++;
        int l = ans.size();
        parse(cnt);
        reverse(ans.begin()+l,ans.begin()+ans.size());
        p++;
        parse(cnt);
    }else if(S[p]==']'){
        return;
    }else if('A' <= S[p] && S[p] <= 'Z'){
        ans += 'A' + ((S[p]-'A'+cnt+2600000)%26);
        cnt = 0;
        p++;
        parse(cnt);
    }else if(S[p] == '?'){
        ans += 'A';
        cnt = 0;
        p++;
        parse(cnt);
    }else if(S[p] == '+'){
        cnt++;
        p++;
        parse(cnt);
    }else if(S[p] == '-'){
        cnt--;
        p++;
        parse(cnt);
    }
    return;
}

int main(){
    while(1){
        cin>>S;
        if(S==".") break;
        ans = "";
        p=0;
        parse(0);
        cout<<ans<<endl;
    }
    return 0;
}
