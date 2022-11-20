#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m; cin >> n >> m; // input
	priority_queue<int> pq[100001];
	int suma[100001];

    for (int i = 0; i < n; i++){ // input
    	int s,r; cin >> s >> r;
    	pq[s].push(r);
    }

    /*
	se itera por las colas de prioridad sumando su valor en la variable
	c. Para cada iteracion se guarda el valor acumulado en el arreglo suma
	donde cada posicion corresponde al numero i de alumnos con una suma valida.
	En la variable ans se guarda la suma valida de mayor valor.
    */

    int ans = 0;
    for (int i = 1; i <= m; i++){ 
    	int k = 0, c = 0;
    	while(!pq[i].empty()){
            c += pq[i].top();
            if(c < 0) break;
            suma[++k] += c;
            ans = max(ans,suma[k]);
            pq[i].pop();
    	}
    }

    cout << ans;

    return 0;
}