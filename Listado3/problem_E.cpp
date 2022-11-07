#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int count, x0, y0; cin >> count >> x0 >> y0;
    map<double,int> m;
    for (int i = 0; i < count; i++){
        double x,y; cin >> x >> y;
        double value;

        if(x - x0 != 0) value = (y-y0)/(x-x0);
        else value = INT_MAX;
        //cout << value << endl;
        m[value]++;

    }
    //for(auto x : m) cout << x.first << " " << x.second << endl;
    cout << m.size() << endl;

    return 0;
}
