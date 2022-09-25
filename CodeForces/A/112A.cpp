#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2; cin >> s1 >> s2;
    int total1 = 0, total2 = 0;
    for (int i = 0; i < s1.length(); i++){
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }
    int ans;
    if(s1 < s2) ans = -1;
    else if(s1 > s2) ans = 1;
    else ans = 0;
    
    cout << ans << endl;

    return 0;
}