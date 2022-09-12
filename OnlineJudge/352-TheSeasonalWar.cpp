#include <bits/stdc++.h>
using namespace std;

char matrix[27][27]; // matriz de tamano 25 mas 2 filas vacias para evitar salir los rangos
bool visited[27][27]; // matriz para marcar las posiciones visitdas

void eagles(int x, int y){
    if(matrix[x][y] == '1' && !visited[x][y]){ // si la posicion es un 1 y no ha sido visitada
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                visited[x][y] = true; // marcamos la posicion visitada
                eagles(x+i,y+j); // recorremos las posiciones alrededor de la posicion inicial
            }
        }
    }
}

int main(){
    int n;
    int loops = 1;
    while(cin >> n){
        for (int i = 0; i < 27; i++){ // inicializamos las matrices vacias
            for (int j = 0; j < 27; j++){
                matrix[i][j] = '0';
                visited[i][j] = false;
            }
        }
        for (int i = 1; i < n+1; i++){ // agregar los elementos a la matriz
            for (int j = 1; j < n+1; j++){
                cin >> matrix[i][j];
            }
        }
        int contador = 0;
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < n+1; j++){
                if(matrix[i][j] == '1' && !visited[i][j]) { // si la posicion es un 1 y no ha sido visitada
                    eagles(i,j); // funcion recursiva
                    contador++; // contador de war eagles
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",loops,contador);
        loops++;
    }
    return 0;
}
