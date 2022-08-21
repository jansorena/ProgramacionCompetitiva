#include<bits/stdc++.h>
using namespace std;

class StrangeComparator{
public:
    vector<string> compareString(vector<string> a, vector<string> b){
        vector<string> resultado(a.size());
        for (int i = 0; i < a.size(); i++){
            if(a[i].length() != b[i].length()) resultado[i] = "No";
            else{
                int iguales = 0;
                for (int j = 0; j < a[i].length(); j++){
                    if(a[i][j] != b[i][j]) iguales++;
                }
                (iguales > 1 ? resultado[i] = "No" : resultado[i] = "Yes");
            }
        }
        return resultado;
    }
};


int main(){
    vector<string> a = {"", "abc", "bde", "ahsdjka"};
    vector<string> b = {"", "qbp", "fde", "ahsdjka"};

    StrangeComparator sc;
    vector<string> ans = sc.compareString(a,b);

    for(auto x : ans) cout << x << " ";

    return 0;
}
