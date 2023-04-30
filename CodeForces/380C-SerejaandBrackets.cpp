// codigo conseguido de : https://github.com/IHR57/Competitive-Programming/blob/master/CodeForces/380C%20(Sereja%20and%20Brackets).cpp

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1000005
using namespace std;

typedef pair<int, int> pii;
char str[MAX];

struct node // estructura para cada nodo del segment tree
{	
    int cs, o, c;     // cs la cantidad de brackets correos, o los brackets abiertos y c los cerrados
}tree[4*MAX];

node combine(node a, node b)
{
    node res;
    int temp = min(a.o, b.c);     // calcula el minimo entre los brackets abiertos y cerrados
    res.cs = a.cs + b.cs + temp;     //incrementa los brackets correctos
    res.o = a.o + b.o - temp;        //suma los brackets abiertos de ambos nodos hijos y resta los que hicieron match (correctos)
    res.c = a.c + b.c - temp;		// mismo para los cerrados

    return res;
}
void build(int nodeNo, int low, int high)
{
    if(low == high){ // nodo hoja
        if(str[low] == '('){ // si el bracket es abierto
            tree[nodeNo].cs = tree[nodeNo].c = 0;
            tree[nodeNo].o = 1;
        }
        else{ // si es cerrado
            tree[nodeNo].cs = tree[nodeNo].o = 0;
            tree[nodeNo].c = 1;
        }
        return;
    }

    int mid = (low + high) >> 1; // construccion del arbol de segmento
    build(nodeNo * 2, low, mid);
    build(nodeNo * 2 + 1, mid + 1, high);

    tree[nodeNo] = combine(tree[nodeNo * 2], tree[nodeNo * 2 + 1]);
}

node query(int nodeNo, int low, int high, int l, int r) // low y high los limites del nodo y l y r los rangos
{
    if(l == low && high == r) // si coincide devuelve el valor del nodo
        return tree[nodeNo];
    int mid = (low + high) >> 1;
    // si esta en el arbol izquierdo
    if(r <= mid){
        return query(nodeNo * 2, low, mid, l, r);
    }
    if(l > mid) // si esta en el arbol derecho
        return query(nodeNo * 2 + 1, mid + 1, high, l, r);

    // si se solapan los rangos se hacen consultas en ambas mitades
    return combine(query(nodeNo * 2, low, mid, l, mid), query(nodeNo * 2 + 1, mid + 1, high, mid + 1, r));
}

int main()
{
    int q;          //number of query
    scanf("%s", str);

    int n = strlen(str);

    scanf("%d", &q);

    int x,  y;

    build(1, 0, n - 1);

    for(int i = 0; i < q; i++){
        scanf("%d %d", &x, &y);
        x--, y--;           //0 based indexing
        node ans = query(1, 0, n - 1, x, y);
        printf("%d\n", ans.cs * 2);
    }

    return 0;
}