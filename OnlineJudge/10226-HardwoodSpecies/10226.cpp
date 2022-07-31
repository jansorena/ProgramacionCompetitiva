#include <bits/stdc++.h>
using namespace std;

int main(){
	int count; cin >> count;
	string s; getline(cin,s); cin.ignore();
	bool first = true;
	for (int i = 0; i < count; ++i){
		if(!first) cout << endl;
		first = false;
		map <string,int> m; // map [nombre] = frecuencia
		int total = 0;
		while(getline(cin,s)){
			if(s.size() == 0) break;
			if(m.count(s)) m[s]++; // si la key existe aumentamos su frecuencia
			else m[s] = 1; // si la key no existe, le asignamos el valor uno
			total++;
		}
		for(auto x : m){
			cout << x.first;
			printf(" %.4f\n",(float)x.second/total * 100); // impresion del procentaje
		}
	}
	return 0;
}
