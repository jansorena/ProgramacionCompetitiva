// codigo conseguido
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN = 3e5 + 10;
const int MOD = 1e9 + 7;
int n, m, k, t;
int a[MAXN];

bool Check(int cnt){
    int temp = 0; // variable que guarda la posicion del arreglo
    for (int i = 1;i <= n;i++){ 
        if (a[i] < temp){ // si el valor es menor que temp
            int ops = temp-a[i]; // minimo numero de operaciones
            if (ops > cnt) // si es mayor no es una alternativa valida. Returna false
                return false; 
        }
        else if (a[i] > temp){ // arreglo no esta ordenado
            int ops = m-a[i]+temp; // operacion para hacer el arreglo ascendente
            if (ops > cnt) // si el valor es mayor a cnt no hay operaciones suficientes para hacer a[i] == temp
                temp = a[i]; //elemento mas pequeño desde la izquierda es temp=a[i]
        }
    }
    return true;
}

int main(){
    cin >> n >> m; 
    for (int i = 1;i <= n;i++) 
        cin >> a[i];
    int l = 0, r = m; // valores busqueda binaria l es 0 y r es el maximo valor que puede haber en el arreglo.
    int res = m; // resultado. En primera instancia m operaciones son suficientes
    while (l < r){
        int mid = (l+r)/2;
        if (Check(mid)){ 
            res = min(res, mid); // guarda el menor valor entre res y mid, que es el numero de operaciones necesarias.
            r = mid;
        }
        else
            l = mid+1;
    }
    cout << res << endl;

    return 0;
}