#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,int> m;
    int n; cin >> n;

    for (int i = 1; i <= n; i++){
        int value; cin >> value;
        m[value] = i;
    }
    
    for(auto x : m){
        cout << x.second << " ";
    }

    return 0;
}
