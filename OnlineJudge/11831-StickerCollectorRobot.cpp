#include <bits/stdc++.h>
using namespace std;

struct Robot{ // estructura con la posicion del robot
    int x;
    int y;
    int orientacion;
};

int main(){
    int N,M,S;
    while(cin >> N >> M >> S){ // entrada de los datos
        Robot r;
        if(N == 0 && M == 0 && S == 0) break;
        char matrix[N][M];
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                cin >> matrix[i][j]; // entrada de cada posicion de la matriz
                if(matrix[i][j] == 'N'){ // orientacion y posicion inicial del robot
                    r.orientacion = 1;
                    r.x = i;
                    r.y = j;
                }
                if(matrix[i][j] == 'S'){
                    r.orientacion = 3;
                    r.x = i;
                    r.y = j;
                }
                if(matrix[i][j] == 'L'){
                    r.orientacion = 2;
                    r.x = i;
                    r.y = j;
                }
                if(matrix[i][j] == 'O'){
                    r.orientacion = 4;
                    r.x = i;
                    r.y = j;
                }     
            }
        }
        int stickers = 0;
        char op;
        for (int i = 0; i < S; i++){
            cin >> op; // ingreso de las operaciones
            if(op == 'D'){ // orientacion del robot
                r.orientacion++;
                if(r.orientacion > 4) r.orientacion = 1;
            }
            if(op == 'E'){
                r.orientacion--;
                if(r.orientacion < 1) r.orientacion = 4;
            }
            if(op == 'F'){ // movimiento del robot, dependiente de la orientacion en que se encuentre
                if(r.orientacion == 1){
                    if(r.x!=0){
                        char aux = matrix[r.x-1][r.y];
                        if(aux!='#'){
                            if(aux == '*'){
                                stickers++;
                                matrix[r.x-1][r.y] = 'r';
                                matrix[r.x][r.y] = '.';
                                r.x = r.x-1;
                            }else{
                                matrix[r.x-1][r.y] = 'r';
                                matrix[r.x][r.y] = '.';
                                r.x = r.x-1;
                            }
                        }
                    }
                }
                if(r.orientacion == 2){
                    if(r.y!=M-1){
                        char aux = matrix[r.x][r.y+1];
                        if(aux!='#'){
                            if(aux == '*'){
                                stickers++;
                                matrix[r.x][r.y+1] = 'r';
                                matrix[r.x][r.y] = '.';
                                r.y = r.y+1;
                            }else{
                                matrix[r.x][r.y+1] = 'r';
                                matrix[r.x][r.y] = '.';
                                r.y = r.y+1;
                            }
                        }
                    }                    
                }
                if(r.orientacion == 3){
                    if(r.x!=N-1){
                        char aux = matrix[r.x+1][r.y];
                        if(aux!='#'){
                            if(aux == '*'){
                                stickers++;
                                matrix[r.x+1][r.y] = 'r';
                                matrix[r.x][r.y] = '.';
                                r.x = r.x+1;
                            }else{
                                matrix[r.x+1][r.y] = 'r';
                                matrix[r.x][r.y] = '.';
                                r.x = r.x+1;
                            }
                        }
                    }                    
                }
                if(r.orientacion == 4){
                    if(r.y!=0){
                        char aux = matrix[r.x][r.y-1];
                        if(aux!='#'){
                            if(aux == '*'){
                                stickers++;
                                matrix[r.x][r.y-1] = 'r';
                                matrix[r.x][r.y] = '.';
                                r.y = r.y-1;
                            }else{
                                matrix[r.x][r.y-1] = 'r';
                                matrix[r.x][r.y] = '.';
                                r.y = r.y-1;
                            }
                        }
                    }                    
                }
            }
        }
        cout << stickers << endl;
    }
    return 0;
}
