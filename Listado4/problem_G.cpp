#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int vacios = 0;
map<pair<int,int>,int> mapa;
char matriz[500][500];
bool visited[500][500];

// vectores de direccion alrededor de una posicion
int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

// dfs para recorrer la matriz
void dfs(pair<int,int> s){
    int x = s.first;
    int y = s.second;

    if(visited[x][y]) return;
    visited[x][y] = true;

    //cout << x << " " << y << endl;

    // se resta una posicion vacia y se marca en el mapa
    vacios--;
    mapa[{x,y}] = 1;

    // si las posiciones vacias son igual a k, para cada posicion en el mapa no marcada se cambia por una X
    // se asegura que todas las posiciones marcadas estan conectadas
    if(vacios == k){

        for(auto t: mapa){
            int x1 = t.first.first;
            int y1 = t.first.second;
            int val = t.second;

            //cout << x1 << " " << y1 << " " << val << endl;
            if(val == 0) matriz[x1][y1] = 'X';
        }
        // impresion de la matriz
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << matriz[i][j];
            }
            cout << endl;
        }
    }

    // recorridos alrededor de la posicion correspondiente
    for (int i = 0; i < 4; i++){
        int adjx = x + dRow[i];
        int adjy = y + dCol[i];

        if(adjx < 0 || adjy < 0 || adjx >= n || adjy >= m || visited[adjx][adjy] || matriz[adjx][adjy] == '#') continue;
        dfs({adjx,adjy});
    }
    

}

int main(){
    cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = false;
            char chr; cin >> chr;
            if(chr == '.') {
                vacios++;
                mapa[{i,j}] = 0;
            }
            matriz[i][j] = chr;
            //cout << matriz[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << vacios << " " << total;

    // dfs a partir de la primera celda vacia
    bool flag = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matriz[i][j] == '.') {
                dfs({i,j});
                flag = true;
                break;
            }

        }
        if(flag) break;
    }

    
    return 0;
}