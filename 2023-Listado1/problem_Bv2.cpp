#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m,b,p;

	while(cin >> n >> m >> b >> p){
		vector<pair<int,int>> adj[n];
		vector<int> bancos,policias;
		
		for (int i = 0; i < m; ++i){
			int v1,v2,v3; cin >> v1 >> v2 >> v3;
			adj[v1].push_back({v2,v3});
			adj[v2].push_back({v1,v3});
		}
		for (int i = 0; i < b; ++i){
			int aux; cin >> aux;
			bancos.push_back(aux);
		}
		for (int i = 0; i < p; ++i){
			int aux; cin >> aux;
			policias.push_back(aux);
		}

		// dijkstra 
		for(auto x : policias){
			priority_queue<pair<int,int>> pq;
			int distancia[n];
		}
	}

	return 0;
}