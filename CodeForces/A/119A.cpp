#include<bits/stdc++.h>
using namespace std;

int mcd(int a, int b){
    if (a == 0 || b == 0) return 0;
    if (a == b) return a;
    if (a > b) return mcd(a-b,b);
    else return mcd(a,b-a);
}


int main(){
    int a,b,n; cin >> a >> b >> n;

    while(n!=0){
        n = n - mcd(a,b);
    }
    
    return 0;
}
