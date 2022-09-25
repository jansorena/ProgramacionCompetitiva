#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, value; cin >> n;
    vector<int> v;

    while(n--){
        cin >> value;
        v.push_back(value);
    }
    unordered_map<int,int> m;
    m[1] = 0; m[2] = 0;
    int aux = v[0];
    int best = 0;
    for (int i = 0; i < v.size(); i++){
        if(v[i] != aux){
            if(v[i] == 1) m[1] = 0;
            else m[2] = 0;
        }
        m[v[i]]++;
        if(min(m[1],m[2]) > best) best = min(m[1],m[2]);
        aux = v[i];
    }
    cout << 2*best << endl;
    return 0;
}