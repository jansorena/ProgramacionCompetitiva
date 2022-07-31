#include <bits/stdc++.h>
using namespace std;

int main(){
    int sets; cin >> sets;
    for (int i = 0; i < sets; i++){
        int N, S, Q, time = 0;
        cin >> N >> S >> Q;
        stack<int> carrier; // 1 carrier
        queue<int> q[N]; // N cantidad de colas

        for (int j = 0; j < N; j++){ // Agregar elementos colas de cada estacion
            int Qi, x; cin >> Qi;
            for (int k = 0; k < Qi; k++){
                cin >> x;
                q[j].push(x);
            }
        }
        int it = 0, count = 0;
        while(true){ 
            it = it%N; // recorrer las estaciones de manera circular
            if(q[it].empty() && carrier.empty()) count++; // contador para verificar si el carrier y las colas estan vacias
            else count = 0;
            while(true){ // Estacion A
                if(!carrier.empty() && carrier.top() == (it + 1)){ // si el elemento de la cola coincide lo descarga en A
                    carrier.pop();
                    time++;
                }
                else{           
                    if(q[it].size() >= Q || carrier.empty()) break; // sale del ciclo si la cola esta lleno o el carrier vacio
                    else{ // si el elemento no coincide lo agrega a la cola
                        q[it].push(carrier.top());
                        carrier.pop();
                        time++;
                    }
                }
            }
            while(true){ // Estacion B
                if(q[it].empty() || carrier.size() >= S) break;
                carrier.push(q[it].front()); // carga elementos al carrier hasta que la cola esta vacia o el carrier lleno
                q[it].pop();
                time++;
            }
            if(count == N){ // si el carrier y todas las colas estan vacias termina la ejecucion
                time-=N*2; // resta el tiempo empleado en comprobar si las colas estan vacias
                break;
            }
            it++;
            time+=2;
        }
        cout << time << endl;
    }
    return 0;
}
