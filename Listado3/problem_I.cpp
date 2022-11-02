#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int n,suma = 0; cin >> n;
	vector<int> v;

	for(int i = 0; i < n; i++){
		int value; cin >> value;
		v.push_back(value);
	}

	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int indices = v[i] + v[j];
			if(indices && !(indices & (indices-1))){
				suma+=1;
			}
				
		}
	}
	
	cout << suma << endl;
	return 0;
}