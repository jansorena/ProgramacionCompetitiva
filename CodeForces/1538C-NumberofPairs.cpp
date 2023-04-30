#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t; cin >> t;

	while(t--){
		int n,l,r; cin >> n >> l >> r;
		vector<long long> array;
		for (int i = 0; i < n; ++i){
			long long ni; cin >> ni;
			array.push_back(ni);
		}
		sort(array.begin(),array.end());
		long long ans = 0;
		for (int i = 0; i < n; ++i){
			auto pointer1 = lower_bound(array.begin()+i+1,array.end(),l-array[i]);
			auto pointer2 = upper_bound(array.begin()+i+1,array.end(),r-array[i]);
			//cout << pointer1-array.begin() << " " << pointer2-array.begin() << endl;
			ans+=pointer2-pointer1;
			
		}
		cout << ans << endl;
	}



	return 0;
}