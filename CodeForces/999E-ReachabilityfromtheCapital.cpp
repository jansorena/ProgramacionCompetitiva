#include <bits/stdc++.h>
using namespace std;

int n,m,s;
vector<int> adj[5001];
//int deg[5001];
bool visited[5001];
bool visited2[5001];

// dfs que marca los nodos visitados
void dfs(int n){
    if(visited[n]) return;
    visited[n] = true;

    //cout << n << endl;

    for(auto u : adj[n]){
        dfs(u);
    }
}
// dfs que permite saber la cantidad total de nodos que puede visitar el nodo dado
int dfs2(int n, int total){
    if(visited2[n]) return 0;
    visited2[n] = true;

    for(auto u : adj[n]){
        total += dfs2(u,1);
    }

    //cout << n << " " << total << endl;

    return total;
}


int main(){
    // inicializacion de los arreglos
    
    //memset(deg,0,sizeof(deg));
    memset(visited,0,sizeof(visited));
    memset(visited2,0,sizeof(visited2));

    cin >> n >> m >> s;
    
    for (int i = 0; i < m; i++){
        int ui, vi; cin >> ui >> vi;
        adj[ui].push_back(vi);
        //deg[vi]++;
    }
    
    /*
    for(int i = 1; i <= n; i++){
        cout << i << " " << deg[i] << endl;
    }
    */

    // realiza el dfs a partir de la capital y se marcan los nodos que alcanzan
    dfs(s);
    vector<pair<int,int>> vec;

    // para cada nodo no visitado se realiza un dfs y se guarda la cantidad de nodos que puede visitar cada nodo
    for (int i = 1; i <= n; i++){
        if(!visited[i]) {
            vec.push_back({dfs2(i,0),i});
            memset(visited2,0,sizeof(visited2));
        }
    }
    
    // ordena el vector de los nodos no visitados de mayor a menor cantidad de ciudades visitadas
    // los nodos que alcanzen la mayor cantidad de ciudades tienen preferencia para armar caminos ya que al abarcar mas nodos
    // minimiza el numero de caminos necesarios
    sort(vec.begin(),vec.end(),greater<>());
    
    // para cada nodo no visitado realizamos un dfs. Cada dfs implica un camino entre la capital y el nodo correspondiente.
    int ans = 0;
    for(auto x : vec){
        if(!visited[x.second]) {
            dfs(x.second);
            ans++;
        }
    }
    cout << ans;
}