#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,l,c,d,p,nl,np;
    priority_queue<int, vector<int>, greater<int>> pq; 
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int beb1 = (k*l)/nl;
    pq.push(beb1);
    int beb2 = c*d;
    pq.push(beb2);
    int beb3 = p/np;
    pq.push(beb3);

    cout << pq.top()/n << endl;

    return 0;
}
