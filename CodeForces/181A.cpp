#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    char c;
    int n,m; cin >> n >> m;
    unordered_map<int,int> abs;
    unordered_map<int,int> ord;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> c;
            if(c == '*'){
                abs[i]++;
                ord[j]++;
            }
        }
    
    }
    for(auto x: abs){
        if (x.second == 1) cout << x.first+1 << " ";
    }
    for(auto y: ord){
        if (y.second == 1) cout << y.first+1 << endl;
    }

    return 0;
}
