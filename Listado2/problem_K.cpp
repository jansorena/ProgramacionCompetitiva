#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        int n,k,number,mouse = 0,salvados = 0; cin >> n >> k;
        priority_queue<int> pq;

        for (int i = 0; i < k; i++){
            cin >> number;
            pq.push(number);
        }
        
        while(!pq.empty()){
            mouse += (n-pq.top());
            pq.pop();
            //cout << mouse << " ";
            if(mouse < n) salvados++;
            else break;
        }
        cout << salvados << endl;
    }
    return 0;
}   