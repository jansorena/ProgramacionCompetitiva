#include <bits/stdc++.h>
using namespace std;

int r,c;

int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

int main(int argc, char const *argv[]){
    cin >> r >> c;
    char matrix [r][c];
    bool visited [r][c] = {false};
    pair<int,int> exit;
    int ans;
    vector<pair<int,int>> v;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            char chr; cin >> chr;
            matrix[i][j] = chr;
            if (chr == 'E') exit = {i,j};
        }
    }
    //cout << exit.first << " " << exit.second << endl;
    queue<pair<pair<int,int>,int>> q;
    q.push({exit,0});
    visited[exit.first][exit.second] = true;

    while(!q.empty()){
        pair <pair<int,int>,int> aux = q.front();
        
        int x = aux.first.first;
        int y = aux.first.second;
        int count = aux.second;

        //printf("%d %d %d\n",x,y,count);

        if(matrix[x][y] == 'S'){
            ans = count;
        }else if(matrix[x][y] != '0' && matrix[x][y] != 'E'){
            v.push_back({int(matrix[x][y]-'0'),count});
        }

        q.pop();

        for (int i = 0; i < 4; i++){
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];

            if(adjx < 0 || adjy < 0 || adjx >= r || adjy >= c || visited[adjx][adjy] || matrix[adjx][adjy] == 'T') continue;

            q.push({{adjx,adjy},count+1});
            visited[adjx][adjy] = true;
        }
    }
    int battles = 0;
    for (auto x : v){
        //cout << x.first << " " << x.second << endl;
        if(x.second <= ans) battles+=x.first;
    }
    
    cout << battles;
    return 0;
}
