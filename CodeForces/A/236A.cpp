#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    unordered_map<char,int> m;
    for (int i = 0; i < s.length(); i++){
        m[s[i]] = 0;
    }
    if(m.size()%2 == 0) cout << "CHAT WITH HER!" << "\n";
    else cout << "IGNORE HIM!" << "\n";
    return 0;
}
