#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n;
vector<pair<int,int>> adj[MAXN];
vector<int> ans;
bool visited[MAXN] = {false};
//int repair[100005];

// dfs que recorre hasta todas la hojas del arbol. Al regresar en la recursion si es un camino problema lo inserta al vector ans y 
// descarta todos los posibles nodos que esten sobre el. Se utiliza un booleano para verificar si se inserto el nodo o no.

bool dfs(int parent, int nodo, int ti){
    bool flag = false;
    visited[nodo] = true;

    for(auto u : adj[nodo]){
        if(u.first == parent) continue;
        flag += dfs(nodo,u.first,u.second);
    }
    //cout << nodo << " " << flag << endl;

    // si no se ha marcado un nodo, lo agrega al vector y returna true
    if(!flag && ti == 2) {
        ans.push_back(nodo);
        flag = true;
    }
    return flag;   
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int xi, yi, ti; cin >> xi >> yi >> ti;
        adj[xi].push_back({yi,ti});
        adj[yi].push_back({xi,ti});
    }

    //memset(repair,0,sizeof(repair));

    // dfs para cada nodo
    for(int i = 1; i < n; i++){
        if(!visited[i]) dfs(0,i,1);
    }
    
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";

    return 0;
}