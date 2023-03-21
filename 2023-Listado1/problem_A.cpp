#include <bits/stdc++.h>
using namespace std;

void dfs(){

}


int main(int argc, char const *argv[]){
    string s;
    while(getline(cin,s)){

        //cout << s << endl;
        int n,m;

        istringstream iss(s);
        iss >> n;
        iss >> m;

        cout << n << " " << m << endl;
        char c;

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                cin >> c;
                cout << c << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
