#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    string s; cin >> s;
    stack<char> stk;

    for (int i = 0; i < s.length(); i++){
        if(stk.empty()){
            stk.push(s[i]);
        }else if(stk.top() == s[i]){
            stk.pop();
        }else{
            stk.push(s[i]);
        }
    }
    
    stk.empty() ? cout << "Yes" : cout << "No";

    return 0;
}
