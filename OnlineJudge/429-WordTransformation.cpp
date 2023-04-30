#include <bits/stdc++.h>
using namespace std;

int distanciaStrings(string a, string b){
	if(a.length()!=b.length()) return 0;
	int distancia = 0;
	for (int i = 0; i < a.length(); ++i) if(a[i] != b[i]) distancia++;
	return distancia;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;

	while(n--){
		vector<string> words;
		map<string,vector<string>> adj;
		map<string,bool> visited;
		map<string,int> distance;
		string s, aux1, aux2;
		
		while(cin >> s){
			if(s == "*") break;
			words.push_back(s);
		}

		cin.ignore();

		for (int i = 0; i < words.size(); ++i){
			for(int j = i+1; j < words.size(); ++j){
				if(distanciaStrings(words[i],words[j]) == 1){
					adj[words[i]].push_back(words[j]);
					adj[words[j]].push_back(words[i]);
					visited[words[i]] = false;
					visited[words[j]] = false;
				}
			}
		}

		while(getline(cin,s)){
			if(s == "") break;
			queue<string> q;
			istringstream iss(s);		
			iss >> aux1 >> aux2;

			//bfs: camino mas corto
			visited[aux1] = true;
			q.push(aux1);
			while(!q.empty()){
				string ss = q.front(); q.pop();
				if(ss == aux2) break;
				for(auto u : adj[ss]){
					if(visited[u]) continue;
					visited[u] = true;
					distance[u] = distance[ss]+1;
					q.push(u);
				}
			}

			cout << aux1 << " " << aux2 << " " << distance[aux2] << endl;
			distance.clear();
			visited.clear();
		}
		
		if(n!=0) cout << endl;
	}

	return 0;
}

