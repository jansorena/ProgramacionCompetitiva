#include<bits/stdc++.h>
using namespace std;

// global

string s;
string bestPalindromo;

// palindromo

void isPalindromo(string s){
    stack<char> myStack;
    for(int i = 0; i < s.length(); ++i) myStack.push(s[i]);
    for(int i = 0; i < s.length(); ++i){
        if(s[i] != myStack.top()) return;
        else myStack.pop();
    }
    if(s > bestPalindromo) bestPalindromo = s;
}

// dfs 
// generar subsets. Como arbol binario.
void dfs(int i, string subset){
    if(i == s.length()){
        isPalindromo(subset);
    }
    else{
        subset+=s[i];
        dfs(i+1,subset);

        subset.pop_back();
        dfs(i+1,subset);
    }
}

// main
int main(int argc, char const *argv[]){
    cin >> s;
    string subset;
    dfs(0,subset);
    cout << bestPalindromo << endl;
    return 0;
}
