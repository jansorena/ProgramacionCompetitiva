#include<bits/stdc++.h>
using namespace std;

int mcd(int a, int b){
    if (a == 0 && b != 0) return b;
    if (a != 0 && b == 0) return a;
    if (a == b) return a;
    if (a > b) return mcd(a-b,b);
    else return mcd(a,b-a);
}

int main(){
    int a, b, n; cin >> a >> b >> n;
    for (int i = 0; ; i++){
        if(i % 2 == 0) {
            int val = mcd(a,n);
            if(n < val){
                cout << 1 << endl;
                break;
            }
            n-=val;
        }
        else{
            int val = mcd(b,n);
            if(n < val){
                cout << 0 << endl;
                break;
            }
            n-=val;
        } 
    }
    return 0;
}
