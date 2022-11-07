#include <bits/stdc++.h>
using namespace std;

bool power2 (long long a){
	if(a && !(a & (a-1))) return true;
	return false;
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int n; cin >> n;
	long long suma = 0;
	vector<long long> v;
	unordered_map<long long,long long> m;

	for(int i = 0; i < n; i++){
		int value; cin >> value;
		if(m.count(value)) m[value]++;
		else{
			v.push_back(value);
			m[value]++;
		}
	}

	//for(auto x : m) cout << x.first << " " << x.second << endl;

	if(m.size() == 1){
		long long aux = m[v[0]];
		if(power2(v[0]+v[0]))
			suma+=(aux*(aux-1))/2; 
		cout << suma << endl;
		return 0;
	}

	for(int i = 0; i < v.size(); i++){
		if(m[v[i]] > 1)
			if(power2(v[i]+v[i])) {
				suma+=(m[v[i]]*(m[v[i]]-1))/2;	
			}
		for(int j = i+1; j < v.size(); j++){
			if(power2(v[i]+v[j]))
				suma+=m[v[i]]*m[v[j]];
		}
	}
	
	cout << suma << endl;
	return 0;
}