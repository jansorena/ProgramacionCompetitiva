#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
bool visited[MAXN];
vector<int> camino;

// dfs desde el ultimo nodo insertado hasta el primero
void dfs(int s){
	if(visited[s]) return;
	visited[s] = true;
	camino.push_back(s); // agrega a un vector por cada recorrido
	for (auto u : adj[s]){
		dfs(u);
	}
}

int main(){
	int n; cin >> n;
	for(int i = 2; i <= n; i++){
		int s; cin >> s;
		adj[i].push_back(s);
	}
	dfs(n);
	for (int i = camino.size()-1; i >= 0; i--){
		cout << camino[i] << " ";
	}
	
	
	return 0;
}