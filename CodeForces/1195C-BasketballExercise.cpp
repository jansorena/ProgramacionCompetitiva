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

	int n; cin >> n;
	ll team1[n], team2[n];
	ll dp[2][n];

	for (int i = 0; i < n; ++i) cin >> team1[i];
	for (int i = 0; i < n; ++i) cin >> team2[i];

	dp[0][0] = team1[0];
	dp[1][0] = team2[0];

	for (int i = 1; i < n; ++i){
		dp[0][i] = max(dp[0][i-1],dp[1][i-1]+team1[i]);
		dp[1][i] = max(dp[1][i-1],dp[0][i-1]+team2[i]);
	}

	cout << max(dp[0][n-1],dp[1][n-1]);

	return 0;
}