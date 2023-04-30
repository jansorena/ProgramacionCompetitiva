#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;

	while(t--){
		int n; cin >> n;
		vector<int> array, arrayunlocked, posunlocked;
		int count = 0;

		for(int i = 0; i < n; ++i){
			int a; cin >> a;
			array.push_back(a);
		}
		
		for (int i = 0; i < n; ++i){
			int b; cin >> b; posunlocked.push_back(b);
			if(b == 0){
				arrayunlocked.push_back(array[i]);
			}
		}

		sort(arrayunlocked.begin(),arrayunlocked.end(),greater<int>());
		
		for (int i = 0; i < n; ++i){
			if(posunlocked[i] == 1) {
				cout << array[i] << " ";
			}
			else{
				cout << arrayunlocked[count++] << " ";
			}
		}
		cout << endl;
	}
}