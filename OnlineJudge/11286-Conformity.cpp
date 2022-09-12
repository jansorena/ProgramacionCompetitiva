#include<bits/stdc++.h>
using namespace std;

int main(){
    int frosh; // numero de frosh
    while(true){
        map<vector<int>,int> m; // map siendo la key el arreglo de clases ordenado y un int que es la frecuencia del arreglo
        cin >> frosh;
        if(frosh == 0) break;
        for (int i = 0; i < frosh; i++){
            vector<int> v;
            for (int j = 0; j < 5; j++){ // agregar las clases al vector v
                int n; cin >> n;
                v.push_back(n);
            }
            sort(v.begin(),v.end()); // ordenar los vectores para poder compararlos y obtener la frecuencia
            if(!m.count(v)) m[v] = 1; // si la key no esta en el map asigna el valor 1
            else m[v]++; // caso contrario suma 1 al valor de la key existe.
        }

        int max = 0, repeticiones = 0; // max es la frecuencia mas alta y repeticiones el numero de veces que aparece en el map
        for(auto x : m){ // iteracion sobre el map
            if(x.second > max) { // encontrar el maximo de frecuencias
                max = x.second;
                repeticiones = 0;
            }
            if(x.second == max) repeticiones++;
        }

        if(max == 1) cout << frosh << endl; // si todas las frecuencias son iguales devuelve el numero de frosh
        else cout << max*repeticiones << endl; // caso contrario devuelve el max*repeticiones
    }
    return 0;
}
