#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int probRes = 0;
    while(n--){
        int a, aux = 0;
        for (int i = 0; i < 3; i++){
            cin >> a;
            if(a == 1) aux++;
        }
        if(aux>=2) probRes++;
    }
    cout << probRes << "\n";
    return 0;
}