#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m,b,p;

	while(cin >> n >> m >> b >> p){
		vector<pair<int,int>> adj[n];
		vector<int> bancos, policias;
		int n1, m1, dis;

		while(m--){
			cin >> n1 >> m1 >> dis;
			adj[n1].push_back({m1,dis});
			adj[m1].push_back({n1,dis});
		}

		while(b--){
			int aux1;
			cin >> aux1;
			bancos.push_back(aux1);
		}
		while(p--){
			int aux1;
			cin >> aux1;
			policias.push_back(aux1);
		}

		int bestDistancia[n] = {INT_MAX};

		for(auto x : policias){
			priority_queue<pair<int,int>> q;
			int distancia[n];
	        for (int i = 0; i < n; i++) distancia[i] = INT_MAX;
	        bool procesado[n] = {false};

	        distancia[x] = 0; // distancia del primer nodo
	        
	        q.push({0,x}); // agrega el primero nodo a la pq

	        while(!q.empty()){
	            int a = q.top().second;
	            q.pop();
	            if(procesado[a]) continue; // si el nodo ya fue visitado
	            procesado[a] = true;
	            for (auto y : adj[a]){
	                int b = y.first;
	                int l = y.second;
	                if(distancia[a]+l < distancia[b]){ //si la distancia del nodo a al nodo b es menor q la distancia que b
	                    distancia[b] = distancia[a]+l;
	                    q.push({-distancia[b],b}); //simbolo negativo para ordenar de mayor a menor
	                }
	            }
	        }

	        for(int i = 0; i < bancos.size(); i++){
	        	if(distancia[bancos[i]] != INT_MAX && distancia[bancos[i]] > bestDistancia[bancos[i]]) bestDistancia[bancos[i]] = distancia[bancos[i]];
	        }
		}

		map<int,vector<int>> mymap;

		for (int i = 0; i < bancos.size(); ++i)
		{
			mymap[bestDistancia[bancos[i]]].push_back(bancos[i]);
		}

		auto it1 = mymap.begin();
		auto it2 = mymap.rbegin();


		if(it1->first == 0){
			cout << it1->second.size() << " " << "*" << endl;
			sort(it1->second.begin(), it1->second.end());
			for(auto x : it1->second){
				cout << x << " ";
			}
			cout << endl;
		}else{
			cout << it2->second.size() << " " << it2->first << endl;
			sort(it2->second.begin(), it2->second.end());
			for(auto x : it2->second){
				cout << x << " ";
			}
			cout << endl;
		}

	}

	


	return 0;
}