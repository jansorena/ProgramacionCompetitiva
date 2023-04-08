/*
Fuente: https://github.com/Kevinwen1999/UVa-solutions/blob/master/12186%20-%20Another%20Crisis.cpp
*/

#include <bits/stdc++.h>

using namespace std;
int N, T;
const int MAXN = 100000 + 10;
vector <int> rooted[MAXN];


// dfs para recorrer el arbol desde la raiz
int dfs(int cur)
{
    if (rooted[cur].empty()) return 1; // si es una hoja retorna 1
    int tot = rooted[cur].size();
    vector <int> temp;
    for (int i = 0 ; i < tot; i++) // para cada nodo recorre recursiva los hijos y los agrega a un vector
        temp.push_back(dfs(rooted[cur][i]));
    sort(temp.begin(), temp.end()); // ordenan ascendetemente de acuerdo a los hijos de cada nodo
    int needed = (tot*T-1) / 100 + 1; // presion de cada nodo redondeado hacia arriba
    int ans = 0;
    for (int i = 0 ;i < needed; i++) // suma de los dfs de los nodos necesarios de acuerdo a la presion
        ans+= temp[i];
    return ans;
}
int main()
{
    while(cin>>N>>T)
    {
        if (!N && !T) break;
        for (int i = 0; i <= N; i++)
            rooted[i].clear(); // inicializacion
        for (int i = 1, x; i <= N; i++)
        {
            cin>>x;
            rooted[x].push_back(i); //lista de adyacencia
        }
        cout<<dfs(0)<<endl; // dfs
    }
}