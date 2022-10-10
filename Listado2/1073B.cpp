#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    int n; cin >> n;
    vector <int> aux,v;
    stack<int> s;
    int visited[n+1] = {0};
    for(int i = 0; i < n; i++){
        int value; cin >> value;
        aux.push_back(value);
    }
    for (int i = aux.size()-1; i >= 0; i--) s.push(aux[i]);
    for(int i = 0; i < n; i++){
        int value; cin >> value;
        if(visited[value] == 1){
            v.push_back(0);
            continue;
        }
        int moves = 0;
        while(!s.empty()){
            int aux = s.top();
            if(value == aux) {
                moves++;
                s.pop();
                v.push_back(moves);
                break;
            }
            else{
                moves++;
                visited[aux] = 1;
                s.pop();
            }
        }
    }
    cout << v[0];
    for (int i = 1; i < v.size(); i++) cout << " " << v[i];
    return 0;
}
