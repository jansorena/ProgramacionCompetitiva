#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = 0;
    int n; cin >> n;
    string s;
    while(n--){
        cin >> s;
        if(s == "++X" || s == "X++") x++;
        if(s == "--X" || s == "X--") x--;
    }
    cout << x << "\n";

    return 0;
}