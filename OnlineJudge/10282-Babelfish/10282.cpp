#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
	map <string,string> m; // map con ambas strings
	while(getline(cin,s)){
		if(s.size() == 0){
			string palabra;
			while(cin >> palabra){ // insercion de las palabras a traducir
				if(palabra.size() == 0) break;
				if(m.count(palabra)) cout << m[palabra] << endl; // impresion
				else cout << "eh" << endl; // impresion en caso que no este en el map
			}
			break;
		}
		istringstream iss(s);
		string p1,p2;
		iss >> p1 >> p2;
		m[p2] = p1; // agregar ambas palabras al diccionario
	}
	return 0;
}
