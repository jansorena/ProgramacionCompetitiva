#include<bits/stdc++.h>
using namespace std;

int main(){
    string n,s; cin >> n;
    int num = 0;
    for(auto i : n){
        if(i == '4' || i == '7') num++;
    }
    bool flag = true;
    stringstream ss;
    ss << num;
    ss >> s;
    for(auto i : s){
        if(i == '4' || i == '7') continue;
        else {
            flag = false;
            break;
        }
    }
    (flag ? cout << "YES" : cout << "NO");
    return 0;
}