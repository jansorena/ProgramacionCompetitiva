#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k, score;
    vector <int> v;
    cin >> n >> k;
    while(n--){
        cin >> score;
        v.push_back(score);
    }
    if(v[k-1] == 0) {
        auto it = lower_bound(v.begin(), v.end(), v[k-1], greater<int>());
        cout << it - v.begin() << "\n";
    }
    else{
        auto it = upper_bound(v.begin(), v.end(), v[k-1], greater<int>());
        cout << it - v.begin() << "\n";
    }
    return 0;
}
