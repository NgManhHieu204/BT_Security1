#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <utility>
#include <cstdlib>
using namespace std;

//=== Caesar ===
string caesarEncrypt(const string &t,int s){
    string r=""; s=(s%26+26)%26;
    for(size_t i=0;i<t.size();i++){
        char c=t[i];
        if(isalpha(c)){ char b=isupper(c)?'A':'a'; r+=char((c-b+s)%26+b);}
        else r+=c;
    } return r;
}
string caesarDecrypt(const string &t,int s){ return caesarEncrypt(t,26-(s%26)); }

//=== Menu ph? ===
int chooseAction() {
    cout<<"\n1. Ma hoa\n2. Giai ma\n0. Quay lai\nChon: ";
    int c; cin>>c; cin.ignore();
    return c;
}

int main() {
    while (1) {
        cout<<"\n==== MENU ====\n1. Caesar\n0. Thoat\nChon: ";
        int c; cin>>c; cin.ignore();
        if (c==0) { system("cls"); break; }

        if (c==1) {
            string text; int shift;
            cout<<"Nhap van ban: "; getline(cin,text);
            cout<<"Nhap khoa (shift): "; cin>>shift; cin.ignore();

            int act = chooseAction();
            if (act==1) cout<<"Ma hoa: "<<caesarEncrypt(text,shift)<<"\n";
            else if (act==2) cout<<"Giai ma: "<<caesarDecrypt(text,shift)<<"\n";
        }
        cout<<"\nNhan Enter de ve menu..."; cin.get();
        system("cls");
    }
    return 0;
}

