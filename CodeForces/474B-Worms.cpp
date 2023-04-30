#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,val,total = 0; cin >> n;
    vector<int> v;

    while(n--){
        cin >> val;
        total += val;
        v.push_back(total);
    }

    int m, caso; cin >> m;

    while(m--){
        cin >> caso;

        auto it = lower_bound(v.begin(),v.end(),caso);
        cout << it - v.begin() + 1 << endl;
    }


    return 0;
}