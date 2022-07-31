#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		priority_queue <int, vector<int>, greater<int>> q; //cola de prioridad ordenada de menor a mayor prioridad
		int val1, val2;
		if(n == 0) break;
		for (int i = 0; i < n; ++i){ //agregar enteros a la cola
			int number; cin >> number;
			q.push(number);
		}
		int costo = 0;
		while(true){
			int suma = q.top(); //extraemos los dos primeros de la cola
			q.pop();
			suma += q.top(); //calculo de la suma de ambos enteros
			q.pop();
			costo += suma; //calculo del costo de la suma
			if(q.empty()) break;
			q.push(suma); //ingresamos nuevamente la suma de ambos numeros a la cola para volver a ordenarlos
		}
		cout << costo << endl; //impresion del costo total
	}
	return 0;
}
