#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char const *argv[]){
    ll t; cin >> t;

    while(t--){
        ll n, value; cin >> n;
        ll lowCandy = INT_MAX, lowOrange = INT_MAX;
        vector<ll> candies, oranges;
        /* input */
        for (int i = 0; i < n; i++){
            cin >> value;
            candies.push_back(value);
            if(lowCandy > value) lowCandy = value;
        }
        for (int i = 0; i < n; i++){
            cin >> value;
            oranges.push_back(value);
            if(lowOrange > value) lowOrange = value;
        }
        //cout << lowCandy << " " << lowOrange << endl;
        ll totalCandies = 0, totalOranges = 0, totalConjunto = 0;
        for (int i = 0; i < n; i++){
            /* total de pasos para igualar al menor de cada arreglo por separado */
            totalCandies += candies[i] - lowCandy;
            totalOranges += oranges[i] - lowOrange;
            /* total de pasos repetidos en cada arreglo */
            totalConjunto += min(candies[i]-lowCandy,oranges[i]-lowOrange);
        }
        //cout << totalCandies << " " << totalOranges << " " << totalConjunto << endl;
        cout << totalCandies+totalOranges-totalConjunto << endl;
    }    

        
    return 0;
}
