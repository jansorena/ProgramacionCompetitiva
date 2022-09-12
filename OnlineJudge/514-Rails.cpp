#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while(cin >> N){   
        if(N == 0) break;
        int x;
        while(true){
            stack<int> s; // Stack estacion
            int max = 0; 
            for (int i = 0; i < N; i++){ // A partir de la combinacion dada se van ingresando los trenes a la estacion
                cin >> x; 
                if(x == 0) break;
                if(x >= max) { // si el elemento es mayor al maximo valor registrado se ingresan esa cantidad al stack y se saca el valor
                    for (int j = max+1; j <= x; j++) s.push(j);
                    s.pop();
                    max = x;
                }else if(s.top() == x) s.pop(); // si el elemento es menor, significa que el vagon ya ingreso y si coincide se saca del stack
            }
            if(x == 0) break;
            if(s.empty()) cout << "Yes" << endl; // Si el orden de combinacion es posible, la estacion estara vacia al final del proceso
            else cout << "No" << endl;
        }
        cout << endl; 
    }   
    return 0;
}
