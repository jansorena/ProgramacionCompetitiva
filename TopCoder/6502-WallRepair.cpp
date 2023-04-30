#include<bits/stdc++.h>
using namespace std;

class WallRepair{
public:
    int bricksRequired(vector<string> wallRows){
        int x = wallRows[0].length();
        int y = wallRows.size();
        bool muro[x];
        for(int i = 0; i < x; i++) muro[i] = false;
        int ladrillos = 0;
        for (int i = 0; i < y; i++){
            for (int j = 0; j < x; j++){
                if(wallRows[i][j] == 'X') muro[j] = true;
                else {
                    if(muro[j]) ladrillos++;
                }
            }
        }
        return ladrillos;
    }
};




int main(){
    vector<string> v = {
".........X............",
"......X..X..X..X......",
"X.......X..X.........X",
"....XXXXX..X.XXXXX...X",
".....X..X..X.........X",
"...X....X..X.........X",
".X...XX..X..X..X......",
".....X...X...XX......X"};


    WallRepair *wr = new WallRepair;
    cout << wr->bricksRequired(v);                   



    return 0;
}
