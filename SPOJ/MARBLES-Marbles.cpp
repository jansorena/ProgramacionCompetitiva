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
    	ll n,k; cin >> n >> k;
    	n--; k--;
    	
    	ll ans = 1; // combinatoria (n-1 k-1)
    	ll count = min(k,n-k);
    	for (int i = 0; i < count; i++){
    		ans *= (n-i);
    		ans /= i+1;
    	}
    	cout << ans << "\n";
    }

    return 0;
}