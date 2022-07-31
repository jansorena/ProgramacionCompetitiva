#include <bits/stdc++.h>
using namespace std;

int main(){

	int count; cin >> count;
	map<int,string> m; // utilizamos un map con la key igual al cumpleaños y valor el nombre

	for (int i = 0; i < count; ++i){
		string name; cin >> name;
		int suma_fechas = 0;
		int multiplicador = 1;

		for (int j = 0; j < 3; ++j){ // Agregamos las fechas como un unico valor entero
			int dates; cin >> dates;
			suma_fechas += dates*multiplicador;
			multiplicador *= 100;
		}
		m[suma_fechas] = name;
	}

	auto x = m.end(); // iterador para acceder al ultimo elemento del map
	x--;
	cout << x->second << endl;

	auto y = m.begin(); // iterador para acceder al primer elemento del map
	cout << y->second << endl;

	return 0;
}