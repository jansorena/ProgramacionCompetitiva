/*
    Greedy/Math

    Verificar que cada elemento del arreglo sea divisible por el primero
    De ser divisibles, se asegura una forma de hacer 0 todos los elementos con excepcion del primero.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            v.push_back(a);
        }
        bool flag = true;
        for(int i = 1; i < n; i++){
            if(v[i]%v[0]!=0){
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
