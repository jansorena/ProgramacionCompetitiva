#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	unordered_map<int,int> m;
	vector<int> v;

	while(cin >> n){
		if(!m.count(n))
			v.push_back(n);
		m[n]++;
	}

	for(auto x: v)
		cout << x << " " << m[x] << endl;
	
	return 0;
}