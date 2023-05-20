#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int value, goodValues = 0; 

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> value;
            if(i == j) goodValues+=value;
            else if(j == n/2) goodValues+=value;
            else if(j == n - 1 - i) goodValues+=value;
            else if(i == n/2) goodValues+=value;
        }
    }
    
    cout << goodValues << "\n";

    return 0;
}
