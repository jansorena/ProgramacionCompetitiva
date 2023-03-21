#include <bits/stdc++.h>
using namespace std;

vector<int> adj[26];
int visited1[26] = {false};
bool visited2[26];
vector<int> ans;
vector<string> str;
bool flag1 = false;

// dfs para detectar ciclos

void dfs1(int s){
    if(!visited1[s]){
        visited1[s] = 1;
        for(auto u : adj[s]){
            dfs1(u);   
        }
        visited1[s] = 2;

    }else{
        if(visited1[s] == 1){
            flag1 = true;
            return;
        }
    }

    
}

// dfs para orden topologico
void dfs2(int s){
    if(visited2[s]) return;
    visited2[s] = true;
    for(auto u : adj[s]){
        dfs2(u);
    }
    ans.push_back(s);
}

int main(){
    int n; cin >> n;
      
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        str.push_back(s);
    }
    // comparar las palabras continuas, si los caracteres son igual continua hasta encontrar uno distinto
    for (int i = 0; i < n-1; i++){
        string s1 = str[i];
        string s2 = str[i+1];

        int size = min(s1.size(),s2.size());
        bool flag2 = true;
        for (int j = 0; j < size; j++){
            if(s1[j] == s2[j]) continue;
            
            adj[s2[j]-'a'].push_back(s1[j]-'a');
            flag2 = false;
            break;
        }
        // si los caracteres son iguales y el tamaño de la primera es mayor que la segunda, no se puede realizar dfs
        if(flag2 && (s1.size() > s2.size())) {
            cout << "Impossible";
            return 0;
        }
    }
    
    /*
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < adj[i].size(); j++){
            cout << char(i+'a') << " " << char(adj[i][j]+'a') << endl;
        }
    }
    */

    // inicializacion array visited1
    memset(visited1,0,sizeof(visited1));

    // detectar ciclos
    for(int i = 0; i < 26; i++){
        if(!visited1[i]) dfs1(i);
    }

    // si hay un ciclo, no es un DAG y no se puede realizar orden topologico
    if(flag1){
        cout << "Impossible" << endl;
        return 0;
    }

    // dfs agregando a un vector al final de la busqueda recursiva
    for(int i = 0; i < 26; i++){
        if(!visited2[i]) dfs2(i);
    }

    // imprimir nuevo abecedario
    for(auto x : ans){
        cout << char(x+'a');
    }

    return 0;
}