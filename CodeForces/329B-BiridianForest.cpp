#include <bits/stdc++.h>
using namespace std;

int r,c;

// matrices para recorrer alrededor de una posicion
int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

int main(int argc, char const *argv[]){
    cin >> r >> c;
    char matrix [r][c];
    bool visited [r][c];
    
    for (int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            visited[i][j] = false;
        }
    }

    pair<int,int> exit;
    int ans = 0;
    vector<pair<int,int>> v;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            char chr; cin >> chr;
            matrix[i][j] = chr;
            if (chr == 'E') exit = {i,j};
        }
    }
    // BFS a partir de la posicion E
    queue<pair<pair<int,int>,int>> q;
    q.push({exit,0});
    visited[exit.first][exit.second] = true;

    while(!q.empty()){
        pair <pair<int,int>,int> aux = q.front();
        
        int x = aux.first.first;
        int y = aux.first.second;
        int count = aux.second;

        // guarda la distancia a la posicion S
        if(matrix[x][y] == 'S'){
            ans = count;
        }
        
        // guarda el valor de cada posicion que no sea E, T o S y la distancia desde E
        if(matrix[x][y] > '0' && matrix[x][y] <= '9'){
            int val = int(matrix[x][y]-'0');
            v.push_back({val,count});
        }

        q.pop();

        // recorrer alrededor de cada posicion
        for (int i = 0; i < 4; i++){
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];

            if(adjx < 0 || adjy < 0 || adjx >= r || adjy >= c || visited[adjx][adjy] || matrix[adjx][adjy] == 'T') continue;

            // push a la cola, con la distancia recorrida hasta el momento
            q.push({{adjx,adjy},count+1});
            visited[adjx][adjy] = true;
        }
    }

    // para cada posicion que tenga una distancia menor o igual a la de S se actualiza el valor de battles
    int battles = 0;
    for (auto x : v){
        if(x.second <= ans) battles += x.first;
    }
    
    cout << battles << endl;

    return 0;
}
