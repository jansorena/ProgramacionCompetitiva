#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	int team[n];

	for (int i = 0; i < n; ++i) cin >> team[i];
	sort(team,team+n);

	int best = 0;

	for (int i = 0; i < n; ++i){
		int low = upper_bound(team,team+n,team[i]+5)-team;
		best = max(best,low-i);
	}
	cout << best;
	return 0;
}