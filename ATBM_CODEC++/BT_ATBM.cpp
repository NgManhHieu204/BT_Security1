#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <cstdlib>
using namespace std;

/* ===== 1. Caesar ===== */
string caesarEncrypt(const string &text, int shift) {
    string out;
    shift = (shift % 26 + 26) % 26;
    for (size_t i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            out += char((c - base + shift) % 26 + base);
        } else out += c;
    }
    return out;
}
string caesarDecrypt(const string &text, int shift) {
    return caesarEncrypt(text, 26 - (shift % 26));
}

/* ===== 2. Vigenere ===== */
string vigenereEncrypt(const string &t, const string &k) {
    string r; size_t j=0;
    for (size_t i=0;i<t.size();i++){
        char c=t[i];
        if(isalpha(c)){
            char base=isupper(c)?'A':'a';
            r+=char((c-base + (toupper(k[j%k.size()])-'A'))%26 + base);
            j++;
        } else r+=c;
    }
    return r;
}
string vigenereDecrypt(const string &t,const string &k){
    string r; size_t j=0;
    for (size_t i=0;i<t.size();i++){
        char c=t[i];
        if(isalpha(c)){
            char base=isupper(c)?'A':'a';
            r+=char((c-base - (toupper(k[j%k.size()])-'A') +26)%26 + base);
            j++;
        } else r+=c;
    }
    return r;
}

/* ===== 3. Affine ===== */
int modInverse(int a,int m){a=(a%m+m)%m;for(int x=1;x<m;x++) if((a*x)%m==1) return x;return -1;}
string affineEncrypt(const string &t,int a,int b){
    string r;
    for(size_t i=0;i<t.size();i++){
        char c=t[i];
        if(isalpha(c)){char base=isupper(c)?'A':'a'; r+=char((a*(c-base)+b)%26 + base);}
        else r+=c;
    }
    return r;
}
string affineDecrypt(const string &t,int a,int b){
    string r; int ai=modInverse(a,26);
    if(ai==-1) return "[a khong kha nghich]";
    for(size_t i=0;i<t.size();i++){
        char c=t[i];
        if(isalpha(c)){char base=isupper(c)?'A':'a'; r+=char((ai*(c-base - b +26))%26 + base);}
        else r+=c;
    }
    return r;
}

/* ===== 4. Playfair ===== */
vector<string> makeMatrix(const string &key){
    bool used[26]={false}; used['J'-'A']=true;
    string s="";
    for(size_t i=0;i<key.size();i++){
        char c=toupper(key[i]);
        if(c<'A'||c>'Z') continue;
        if(c=='J') c='I';
        if(!used[c-'A']){used[c-'A']=true; s+=c;}
    }
    for(char c='A';c<='Z';c++){
        if(c=='J') continue;
        if(!used[c-'A']){used[c-'A']=true; s+=c;}
    }
    vector<string> m;
    for(int i=0;i<5;i++) m.push_back(s.substr(i*5,5));
    return m;
}
pair<int,int> pos(const vector<string>&m,char c){
    if(c=='J') c='I';
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(m[i][j]==c) return make_pair(i,j);
    return make_pair(-1,-1);
}
string playfair(const string &text,const string &key,bool enc){
    vector<string> m=makeMatrix(key);
    string t="";
    for(size_t i=0;i<text.size();i++){
        char c=toupper(text[i]);
        if(c<'A'||c>'Z') continue;
        if(c=='J') c='I';
        t+=c;
    }
    string r="";
    for(size_t i=0;i<t.size();i+=2){
        char a=t[i], b=(i+1<t.size())?t[i+1]:'X';
        if(a==b){ b='X'; i--; }
        pair<int,int> pa=pos(m,a), pb=pos(m,b);
        if(pa.first==pb.first){
            r+=m[pa.first][(pa.second+(enc?1:4))%5];
            r+=m[pb.first][(pb.second+(enc?1:4))%5];
        } else if(pa.second==pb.second){
            r+=m[(pa.first+(enc?1:4))%5][pa.second];
            r+=m[(pb.first+(enc?1:4))%5][pb.second];
        } else {
            r+=m[pa.first][pb.second];
            r+=m[pb.first][pa.second];
        }
    }
    return r;
}

/* ===== 5. Hoan vi ===== */
string permEncrypt(const string &t,const vector<int>&k){
    string r="";
    for(size_t i=0;i<t.size();i+=k.size())
        for(size_t j=0;j<k.size();j++){
            size_t pos=i+k[j]-1;
            if(pos<t.size()) r+=t[pos];
        }
    return r;
}
string permDecrypt(const string &c,const vector<int>&k){
    string r(c.size(),' ');
    size_t b=k.size();
    for(size_t i=0;i<c.size();i+=b)
        for(size_t j=0;j<b;j++){
            size_t pos=i+k[j]-1;
            if(pos<c.size()) r[pos]=c[i+j];
        }
    return r;
}

/* Menu ph? */
int chooseAction(){
    cout<<"\n1. Ma hoa\n2. Giai ma\n0. Quay lai\nChon: ";
    int x; cin>>x; cin.ignore();
    return x;
}

int main(){
    while(true){
        cout<<"\n===== MENU CHINH =====\n"
            <<"1. Caesar\n2. Vigenere\n3. Affine\n4. Playfair\n5. Hoan vi\n0. Thoat\nChon: ";
        int c; if(!(cin>>c)) break;
        cin.ignore();
        if(c==0){ system("cls"); break; }

        string text,key;
        int action;

        switch(c){
        case 1:{
            int shift;
            cout<<"Nhap van ban: "; getline(cin,text);
            cout<<"Nhap shift: "; cin>>shift; cin.ignore();
            action = chooseAction();
            if(action==1) cout<<"Ma hoa: "<<caesarEncrypt(text,shift)<<"\n";
            else if(action==2) cout<<"Giai ma: "<<caesarDecrypt(text,shift)<<"\n";
            break;}
        case 2:{
            cout<<"Nhap van ban: "; getline(cin,text);
            cout<<"Nhap khoa: "; getline(cin,key);
            action = chooseAction();
            if(action==1) cout<<"Ma hoa: "<<vigenereEncrypt(text,key)<<"\n";
            else if(action==2) cout<<"Giai ma: "<<vigenereDecrypt(text,key)<<"\n";
            break;}
        case 3:{
            int a,b;
            cout<<"Nhap van ban: "; getline(cin,text);
            cout<<"Nhap a: "; cin>>a;
            cout<<"Nhap b: "; cin>>b; cin.ignore();
            action = chooseAction();
            if(action==1) cout<<"Ma hoa: "<<affineEncrypt(text,a,b)<<"\n";
            else if(action==2) cout<<"Giai ma: "<<affineDecrypt(text,a,b)<<"\n";
            break;}
        case 4:{
            cout<<"Nhap van ban: "; getline(cin,text);
            cout<<"Nhap khoa: "; getline(cin,key);
            action = chooseAction();
            if(action==1) cout<<"Ma hoa: "<<playfair(text,key,true)<<"\n";
            else if(action==2) cout<<"Giai ma: "<<playfair(text,key,false)<<"\n";
            break;}
        case 5:{
            int n;
            cout<<"Nhap van ban: "; getline(cin,text);
            cout<<"Nhap do dai khoa: "; cin>>n;
            vector<int> k(n);
            cout<<"Nhap day khoa (vd 3 1 2 ...): ";
            for(int i=0;i<n;i++) cin>>k[i];
            cin.ignore();
            action = chooseAction();
            if(action==1) cout<<"Ma hoa: "<<permEncrypt(text,k)<<"\n";
            else if(action==2) cout<<"Giai ma: "<<permDecrypt(text,k)<<"\n";
            break;}
        }

        cout<<"\nNhan Enter de ve menu chinh...";
        cin.get();
        system("cls");
    }
    return 0;
}

