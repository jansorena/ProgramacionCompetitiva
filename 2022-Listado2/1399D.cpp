#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<char> vi;
        vector<int> ans;
        for (int i = 0; i < n; i++){
            char value; cin >> value;
            vi.push_back(value);
        }
        stack<pair<string,int>> stkCeros, stkUnos;
        string aux = "";
        int contador = 1;
        for (int i = 0; i < n; i++){
            if(vi[i] == '0'){
                if(stkUnos.empty()) {
                    stkCeros.push({aux+vi[i],contador});
                    ans.push_back(contador);
                    contador++;
                }
                else{
                    string aux2 = stkUnos.top().first;
                    aux2 += vi[i];
                    stkCeros.push({aux2,stkUnos.top().second});
                    ans.push_back(stkUnos.top().second);
                    stkUnos.pop();
                }
            }else{
                if(stkCeros.empty()) {
                    stkUnos.push({aux+vi[i],contador});
                    ans.push_back(contador);
                    contador++;
                }
                else{
                    string aux2 = stkCeros.top().first;
                    aux2 += vi[i];
                    stkUnos.push({aux2,stkCeros.top().second});
                    ans.push_back(stkCeros.top().second);
                    stkCeros.pop();
                }
            }
        }

        cout << stkCeros.size()+stkUnos.size() << endl;
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];

        cout << endl;
        

    }

    return 0;
}
