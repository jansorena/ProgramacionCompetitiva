#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t; cin >> t;

	while(t--){
		int n; cin >> n;
		vector<int> v(n), temp;
		for (int i = 0; i < n; ++i) cin >> v[i];
		int l; cin >> l;
		temp.push_back(v[0]);
		for (int i = 1; i < n; ++i){
			if(v[i] > temp.back()){
				temp.push_back(v[i]);
			}else{
				int aux = lower_bound(temp.begin(),temp.end(),v[i])-temp.begin();
				temp[aux] = v[i];
			}
		}
		if (l > temp.size() || l <= 0 || n == 0) cout << -1 << endl;
		else cout << temp[l-1];

	}

	return 0;
}