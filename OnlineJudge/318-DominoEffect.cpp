#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    int n, m;
    int cases = 1;
    while(cin >> n){
        if(n == 0) break;
        cin >> m;
        int distance[n+1]; // arreglo con las distancias minimas
        bool processed[n+1] = {false}; // nodos visitados
        vector <pair<int,int>> adj[501]; // lista adyacencia

        for (int i = 0; i < m; i++){
            int a,b,l;
            cin >> a >> b >> l;
            adj[a].push_back({b,l});
            adj[b].push_back({a,l});
        }
        // algoritmo dijkstra
        priority_queue<pair<int,int>> q;
        distance[1] = 0; // distancia del primer nodo
        for (int i = 2; i < n+1; i++) distance[i] = INT_MAX; // valor INF
        q.push({0,1}); // agrega el primero nodo a la pq

        while(!q.empty()){
            int a = q.top().second;
            q.pop();
            if(processed[a]) continue; // si el nodo ya fue visitado
            processed[a] = true;
            for (auto x : adj[a]){
                int b = x.first;
                int l = x.second;
                if(distance[a]+l < distance[b]){ //si la distancia del nodo a al nodo b es menor q la distancia que b
                    distance[b] = distance[a]+l;
                    q.push({-distance[b],b}); //simbolo negativo para ordenar de mayor a menor
                }
            }
        }
        /*
        for (int i = 1; i < n+1; i++){
            cout << i << " " << distance[i] << endl;
        } 
        */

        //para cada nodo encontrar el mayor tiempo usando las distancias minimas
        double time = 0;
        int node1, node2 = 0;
        
        //recorremos cada nodo buscando el mayor tiempo entre ese nodo y sus adyacentes
        for (int i = 1; i < n+1; i++){
            if(distance[i] >= time) { // buscamos la mayor de las distancias minimas
                time = distance[i];
                node1 = i;
                node2 = 0;
            }
            for (auto x : adj[i]){ // comprobar nodos adyacentes
                int b = x.first;
                int l = x.second;

                double aux = (distance[i]+distance[b]+l)/2.0;
                if(aux > time){
                    time = aux;
                    node1 = i;
                    node2 = b;
                }
            }    
        }
        //impresion
        if(node2 == 0) printf("System #%d\nThe last domino falls after %.1f seconds, at key domino %d.\n",cases,time,node1);
        else printf("System #%d\nThe last domino falls after %.1f seconds, between key dominoes %d and %d.\n",cases,time,node1,node2);      
        cases++;
        cout << endl;
    }
    return 0;
}
