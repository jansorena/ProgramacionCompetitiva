#include <bits/stdc++.h>
using namespace std;
#define for(i,n) for(int i = 0; i < n; i++)

int main(){

	int n,k,a;
	long long suma = 0;
	cin >> n >> k;
	priority_queue<int,vector<int>,greater<int>> pq;
	vector<int> v1, v2;

	for(i,n){
		int aux; cin >> aux;
		v1.push_back(aux);
	}

	cin >> a;

	for(i,n){
		int aux; cin >> aux;
		v2.push_back(aux);
	}

	bool flag = true;

	for(i,n){
		pq.push(v2[i]);

		if(v1[i] <= k){
			continue;
		}

		while(v1[i] > k){
			if(!pq.empty()){
				suma += pq.top();
				pq.pop();
				k += a;
			}else{
				suma = -1;
				flag = false;
				break;
			}
		}
		if(!flag) break;
	}

	cout << suma << endl;
	return 0;
}