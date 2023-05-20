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

    // 2 impares suman un numero par
    // unica solucion son primos gemelos (2,n-2)

    int n; cin >> n;
    n -= 2;
    bool flag = true;
    if(n < 2) flag = false;
    else{
        for(int i = 2; i < n; i++){
            if(n%i == 0) {
                flag = false;
                break;
            }
        }
    }
    (flag ? cout << 2 << " " << n : cout << -1);
    return 0;
}