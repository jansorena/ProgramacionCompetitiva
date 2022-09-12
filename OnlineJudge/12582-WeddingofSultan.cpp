#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    for (int i = 0; i < T; i++){
        string str; cin >> str; // string con los nodos
        map <char,int> m; // map para imprimir en orden alfabetico
        stack <char> s; // stack (similar al dfs)
        s.push(str[0]); // empujar el primer nodo
        for (int j = 1; j < str.size(); j++){
            if(str[j] == s.top()) {// si el nodo es igual al primero del stack, es un nodo terminal
                s.pop(); // sacamos el nodo del stack
            }
            else{ // si el nodo no es igual, hay una conexion entre ese nodo y el anterior
                m[str[j]]++; // sumamos la conexion al nodo visitado
                m[s.top()]++; // sumamos la conexion al nodo anterior
                s.push(str[j]); // agregamos el nodo visitado al stack
            }
        }
        cout << "Case " << i+1 << endl; // impresion
        for(auto x : m){
            cout << x.first << " = " << x.second << endl;
        } 
    }
    return 0;
}
