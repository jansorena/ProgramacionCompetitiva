#include <bits/stdc++.h>
using namespace std;


char matrix [102][102];
bool visited [102][102] = {false};
int cont = 0;
int n,m;

void dfs(int x, int y){
    if(!visited[x][y] && matrix[x][y] == '@'){
        visited[x][y] = true;
        for (int i = -1; i <= 1; ++i){
            for(int j = -1; j <= 1; j++){
                dfs(x+i,y);
            }
        }
    }
}


int main(int argc, char const *argv[]){

    while(cin >> m >> n){
        
        memset(matrix, 0, sizeof matrix);
        memset(visited, false, sizeof visited);

        cont = 0;

        if(m == 0) break;
        
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                cin >> matrix[i][j];
                //cout << matrix[i][j] << " ";
            }   
        }

        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                if(!visited[i][j] && matrix[i][j] == '@') {
                    dfs(i,j);
                    cont++;
                }
            }
        }
        cout << cont << endl;
    }
    return 0;
}
