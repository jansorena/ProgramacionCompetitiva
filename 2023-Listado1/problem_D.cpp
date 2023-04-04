#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int n,t;
	while(cin >> n >> t){
		if(n == 0 && t == 0) break;
		vector<int>adj[n+1];
		map<int,int> m;
		for (int i = 1; i <= n; ++i){
			int aux; cin >> aux;
			adj[aux].push_back(i);
			m[aux]++;
		}
		for(int i = 0; i <= n; ++i){
			cout << i << " " << adj[i].size() << endl;
		}
	}


	return 0;
}