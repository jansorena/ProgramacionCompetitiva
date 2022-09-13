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
        sort(v.begin(),v.end());
        bool flag = true;
        for(int i = 0; i < v.size(); i++){
            if(i == v.size()-1) break;
            if(abs(v[i]-v[i+1]) > 1){
                flag = false;
                break;
            }
        }
        (flag ? cout << "YES" << endl : cout << "NO" << endl);
    }

    return 0;
}
