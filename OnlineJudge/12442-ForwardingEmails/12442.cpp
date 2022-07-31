#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    for (int i = 0; i < T; i++){
        int N; cin >> N;
        vector<int> adj[N+1]; // lista de adyacencia
        for (int j = 0; j < N; j++){ // ingreso de los datos
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int mejorNodo = 1;
        int mejorSuma = 0;
        bool globalVisit[N+1] = {false}; // visita global de los nodos

        for (int j = 1; j < N+1; j++){ // dfs para cada nodo
            if(globalVisit[j]) continue; // si el nodo ya se visito no es necesario volver a revisarlo
            int suma = 0;   // ya que su suma es igual o menor a una visita anterior
            bool visited[N+1] = {false}; // visita local de los nodos
            stack <int> stack; // dfs
            stack.push(j);
            while(!stack.empty()){
                int s = stack.top();
                stack.pop();
                if(visited[s]) continue;
                visited[s] = true;
                globalVisit[s] = true;
                suma++;
                for(auto x : adj[s]){
                    if(!visited[x]) stack.push(x);
                }
            }
            if(suma > mejorSuma) { // si la suma del nodo es mayor a los ya visitados
                mejorSuma = suma;
                mejorNodo = j;
            }
        }
        printf("Case %d: %d\n",i+1,mejorNodo);
    }
    return 0;
}
