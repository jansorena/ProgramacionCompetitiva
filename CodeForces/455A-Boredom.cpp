#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n; 
	ll maxvalue = 0;
	ll v[MAXN];
	ll dp[MAXN];
	memset(v,0,sizeof v);
	memset(dp,0,sizeof dp);

	cin >> n;

	for (int i = 0; i < n; ++i){
		ll aux; cin >> aux;
		maxvalue = max(maxvalue,aux);
		v[aux]++;
	}

	dp[1] = v[1];

	for (int i = 2; i <= maxvalue; ++i){
		dp[i] = max(v[i]*i + dp[i-2], dp[i-1]);
	}

	cout << *max_element(dp,dp+maxvalue+1);

	return 0;
}