#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	map<int,int> m;
	for (int i = 0; i < n; ++i){
		int value; cin >> value;
		m[value] = 0;
	}
	//cout << m.size() << endl;
	if(m.size() == 1 || m.size() == 2) {
		cout << "YES";
		return 0;
	}

	if(m.size() >= 4) {
		cout << "NO";
		return 0;
	}

	vector <int> v;
	for(auto x : m){
		v.push_back(x.first);
		//cout << x.first << endl;
	}
	
	if(v[1]+v[1] == v[2]+v[0]) cout << "YES";
	else cout << "NO";

	return 0;
}