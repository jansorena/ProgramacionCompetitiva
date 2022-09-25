#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int total = 0;
    int best = 0;

    while(n--){
        int a, b; cin >> a >> b;
        total = total - a + b;
        if(total > best) best = total;
    }
    cout << best << endl;
    return 0;
}