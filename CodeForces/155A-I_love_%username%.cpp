/*
    Brute Force
    Guardar variables del mejor y peor valor e ir comparando
*/

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    int perfomance = 0;
    vector<int> v;

    while(n--){
        int a; cin >> a;
        v.push_back(a);
    }

    int best = v[0];
    int worst = v[0];

    for(auto x:v){
        if(x > best){
            best = x;
            perfomance++;
        }
        if(x < worst){
            worst = x;
            perfomance++;
        }
    }
    
    cout << perfomance << endl;

    return 0;
}
