#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v;
        while (n--){
            int a; cin >> a;
            v.push_back(a);
        }
        /* algoritmo */
        for (int i = 0; i < v.size(); i++){
            if(i == v.size()-1) break;
            cout << "v[i] : " << v[i] << endl;
            for (int j = i+1; j < v.size(); j++){
                cout << "v[j] : " << v[j] << endl;
                if(abs(v[i]-v[j]) <= 1){
                    int pos;
                    (v[i] > v[j] ? pos = i : pos = j);
                    v.erase(v.begin()+pos);
                    i = 0;
                }
            }
        }
        
        (v.size() == 1 ? cout << "YES" << endl : cout << "NO" << endl);
        
    }

    return 0;
}
