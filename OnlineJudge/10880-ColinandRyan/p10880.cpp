#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; cin >> cases;
    for (int i = 0; i < cases; i++){
        vector <int> v;
        int c,r; cin >> c >> r;     
        int num = c-r;
        if(c == r) cout << "Case #" << i+1 << ": 0" << endl; // en caso que c y r sean iguales imprime 0 y sigue a la sgte iteracion
        else{
            for (int j = 1; j <= sqrt(num); j++){
                if (num%j == 0){ // verifica si es division exacta
                    if(num/j == j && j > r) v.push_back(j); // si el divisor es igual al cuociente y a la vez es mayor que r lo agregamos una vez al vector
                    else{ // caso contrario, agregamos ambos valores al vector, considerando que el cuociente tambien es divisor del numero.
                        if(j > r) v.push_back(j);
                        if(num/j > r) v.push_back(num/j);
                    }    
                }
            }
            sort(v.begin(),v.end()); // sort en orden ascendente
            cout << "Case #" << i+1 <<":";
            for (int k = 0; k < v.size(); k++) cout << " " << v[k];
            cout << endl;
        }
    }
    return 0;
}