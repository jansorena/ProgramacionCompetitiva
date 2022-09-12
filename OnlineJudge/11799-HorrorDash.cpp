#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; cin >> cases;
    for (int i = 0; i < cases; i++){
        int n, max = 0; cin >> n;
        for (int j = 0; j < n; j++){ // Encontrar el maximo valor en el arreglo
            int t; cin >> t;
            if(t >= max) max = t;
        }
        printf("Case %d: %d\n",i+1,max);
    }
    return 0;
}