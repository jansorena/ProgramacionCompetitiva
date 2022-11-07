#include <bits/stdc++.h>
using namespace std;
 
bool power2 (int a){
	if(a && !(a & (a-1))) return true;
	return false;
}
 
int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int n,suma = 0; cin >> n;
	vector<int> v;
	map<int,int> m;
 
 
	for(int i = 0; i < n; i++){
		int value; cin >> value;
		m[value]++;
	}
 
	for(auto x : m){
		
		if(x.second > 1) {
			if(power2(x.first + x.first)) suma+=(x.second*(x.second-1))/2;
		}else{
			for(int i = 0; i < v.size(); i++){
				if(m[v[i]] > 1){
					if(power2(v[i]+x.first)) suma+=(x.second*(x.second-1))/2;
				}else if(power2(v[i]+x.first)) suma+=1;
			}
		}
		v.push_back(x.first);
	}
	//for (auto x : v) cout << x << endl;
	cout << suma << endl;
	return 0;
}