#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    int a,b;
    int sol = 0;
    cin >> n >> m;
    for (b = 0; b <= sqrt(m); b++){
        a = m - b*b;
        if(a >=0 && b == n-a*a) sol++;
    }
    cout << sol << "\n";
    
    return 0;
}