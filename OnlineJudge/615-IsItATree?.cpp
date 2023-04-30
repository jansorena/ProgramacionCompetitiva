#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> adj;
map<int,bool> visitados;

bool isTree = true;

// dfs usando 2 mapas
void dfs(int s, int e){
	visitados[s] = true;
	//cout << "nodo padre: " << e << " nodo hijo: " << s << endl;
	for(auto u : adj[s]){
		if(!visitados[u]) dfs(u,s);
        else if(u != e) isTree = false;    
	}
}

int main(){
	int n,m,casos = 1;
	while(cin >> n >> m && n >= 0){
		if(n != 0 && m != 0){
			adj[n].push_back(m);
			adj[m].push_back(n);
			visitados[n] = false;
			visitados[m] = false;
		}else{
			int raiz = 0;
			for(auto x : adj){ // si corre 2 veces el dfs hay mas de una raiz
				if(!visitados[x.first]){
					raiz++;
					dfs(x.first,-1);
				}
			}	
			for(auto x : adj){ 
				if(!visitados[x.first]){
					isTree = false;
					break;
				}
			}
			if(adj.empty()) raiz++; // caso 0 0
			if (isTree && raiz == 1) cout << "Case " << casos++ << " is a tree." << endl;
            else cout << "Case " << casos++ << " is not a tree." << endl;

            adj.clear();
			visitados.clear();
			isTree = true;
		}
	}
	return 0;
}