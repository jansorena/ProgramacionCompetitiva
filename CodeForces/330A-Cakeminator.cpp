#include <bits/stdc++.h>
using namespace std;

int main(){
    int c,r; cin >> c >> r;
    unordered_map<int,int> rows, columns;
    char matrix[c][r];
    int total = 0;

    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            cin >> matrix[c][r];
            if(matrix[c][r] == 'S'){
                rows[i] = 0;
                columns[j] = 0;
            }
        }
    }

    for (int i = 0; i < c; i++){
        for (int j = 0; j < r; j++) {
            if(rows.count(i) && columns.count(j)) continue;
            else total++;
        }
        
    }

    cout << total << endl;

    return 0;
}