#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int total, vacios = 0;
map<pair<int,int>,int> mapa;
char matriz[500][500];
bool visited[500][500];

int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

void dfs(pair<int,int> s){
    int x = s.first;
    int y = s.second;

    if(visited[x][y]) return;
    visited[x][y] = true;

    //cout << x << " " << y << endl;
    vacios--;
    mapa[{x,y}] = 1;
    if(vacios == k){

        for(auto t: mapa){
            int x1 = t.first.first;
            int y1 = t.first.second;
            int val = t.second;

            //cout << x1 << " " << y1 << " " << val << endl;
            if(val == 0) matriz[x1][y1] = 'X';
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << matriz[i][j];
            }
            cout << endl;
        }
    }

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
    total = vacios - k;
    //cout << vacios << " " << total;

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