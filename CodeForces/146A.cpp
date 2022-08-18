#include<bits/stdc++.h>
using namespace std;

int main(){
    int l; cin >> l;
    string s = "";
    bool flag = false;
    while(l--){
        char c; cin >> c;
        if(c != '4' && c != '7') flag = true;
        s+=c;
    }
    if(flag) cout << "NO" << endl;
    else{
        int suma1 = 0, suma2 = 0;
        for (int i = 0; i < s.length()/2; i++){
            int val = s[i] - 48;
            suma1+= val;
        }
        for (int i = s.length()/2; i < s.length(); i++){
            int val = s[i] - 48;
            suma2+= val;
        }
        (suma1 == suma2 ? cout << "YES" : cout << "NO");
    }
    return 0;
}
