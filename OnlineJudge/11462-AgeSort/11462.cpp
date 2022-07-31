#include <bits/stdc++.h>
using namespace std;

int main(){
    // fast IO
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
    	vector <int> v;
    	int n; cin >> n;
    	if(n == 0) break;
    	for (int i = 0; i < n; ++i){ // ingresar elementos al vector
    		int val; cin >> val;
    		v.push_back(val);
    	}
    	sort(v.begin(), v.end()); // sort
    	cout << v[0]; // print
    	for (int i = 1; i < v.size(); ++i){
    		cout << " " << v[i];
    	}
    	cout << "\n";
    }
	return 0;
}