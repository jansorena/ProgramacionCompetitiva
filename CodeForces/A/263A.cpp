#include<bits/stdc++.h>
using namespace std;

int main(){
    int number;
    map<int,int> m;
    for (int i = 0; i < 4; i++){
        cin >> number;
        m[number] = 0;
    }
    cout << 4-m.size() << "\n";
    return 0;
}
