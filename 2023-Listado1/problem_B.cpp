#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m,b,p;

	while(cin >> n >> m >> b >> p){
		vector<pair<int,int>> adj[n];
		vector<int> bancos,policias;
		int max_dis[n];
		for (int i = 0; i < n; ++i) max_dis[i] = -1;
		
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
		
		priority_queue<pair<int,int>> q;
		int distancia[n];
		bool visitado[n];
		for (int i = 0; i < n; i++) distancia[i] = INT_MAX;
		for (int i = 0; i < n; i++) visitado[i] = false;

		for(auto x : policias){
			distancia[x] = 0;
			q.push({0,x});
		}

		while(!q.empty()){
			int a = q.top().second;
	        q.pop();
	        if(visitado[a]) continue; 
	        visitado[a] = true;
	        for (auto y : adj[a]){
	            int b = y.first;
	            int l = y.second;
	            if(distancia[a]+l < distancia[b]){
	                distancia[b] = distancia[a]+l;
	                q.push({-distancia[b],b}); 
	            }
	        }
		}

		for(auto banco : bancos) max_dis[banco] = max(max_dis[banco],distancia[banco]);
		
		vector<int> ans;
		int max_value = 0;
		for (int i = 0; i < bancos.size(); ++i){
			max_value=max(max_value,max_dis[bancos[i]]);
		}

		for (int i = 0; i < bancos.size(); ++i){
			if(max_dis[bancos[i]] == max_value) ans.push_back(bancos[i]);
		}

		if(max_value != INT_MAX) cout << ans.size() << " " << max_value << endl;
		else cout << ans.size() << " *" << endl;

		sort(ans.begin(),ans.end());
		cout << ans[0];
		for(int i = 1; i < ans.size(); ++i) cout << " "<< ans[i];
		cout << endl;

	}

	return 0;
}