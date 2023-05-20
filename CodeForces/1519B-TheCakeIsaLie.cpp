#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
#define ll unsigned long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t; cin >> t;
	while(t--){
		int n,m,k;
		cin >> n >> m >> k;
		int cost = n*m-1;
		//cout << cost << endl;
		if(cost == k) cout << "YES" << "\n";
		else cout << "NO" << "\n";
 	}


	return 0;
}