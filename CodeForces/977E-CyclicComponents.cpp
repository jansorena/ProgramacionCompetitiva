#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;

vector<int> adj [MAXN];
bool visited[MAXN];
vector <int> path;

// dfs
void dfs(int s){
    if(visited[s]) return;
    visited[s] = true;

    // se agrega cada nodo visitado al vector path
    path.push_back(s);

    for(auto u : adj[s]){
        dfs(u);
    }
}


int main(){
    int n,m; cin >> n >> m;

    // input
    for (int i = 0; i < m; i++){
        int node1,node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    
    int ans = 0;

    // realiza dfs para cada nodo
    for (int i = 1; i <= n; i++){
        if(!visited[i]) {
            path.clear(); // limpia el vector para cada dfs
            dfs(i);
            // si hay menos de 3 nodos por cada dfs, continua a la sgte iteracion
            if(path.size() < 3) continue;
            
            bool flag = true;
            for(auto x : path){
                // si el grado del nodo es distinto de 2 no hay un ciclo valido
                if (adj[x].size() != 2) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}