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
	int comb = 3*n;
	ll num = 1; ll sum6 = 1;

	while(comb--){
		num=num*3 % (ll)(pow(10,9)+7);
	}

	while(n--){
		sum6 = sum6*7 % (ll)(pow(10,9)+7);
	}
	
	cout << (num-sum6 + (ll)(pow(10,9)+7)) % (ll)(pow(10,9)+7);


	return 0;
}