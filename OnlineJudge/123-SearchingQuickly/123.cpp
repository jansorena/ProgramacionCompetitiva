#include <bits/stdc++.h>
using namespace std;

// funcion para sort . Primero orden alfabetico de la keyword, luego numero de ingreso
// y luego posicion de la keyword dentro del string

// se guarda un par doble ((keyword,posicion),(indice titulo,titulo))
bool ordenar(const pair<pair<string,int>,pair<int,string>> &a,const pair<pair<string,int>,pair<int,string>> &b)
{
    if (a.first.first < b.first.first) return true;
    if (a.first.first > b.first.first) return false;

    if (a.second.first < b.second.first) return true;
    if (a.second.first > b.second.first) return false;

    return a.first.second < b.first.second;
}


int main(){
	string str;
	vector<string> ignoradas;
	vector<string> titulos;
	vector<pair <pair<string,int>, pair<int,string>>> vector_pair;
	while(cin >> str){ // input de las palabras a ignorar
		if(str == "::") break;
		ignoradas.push_back(str);
	}
	cin.ignore();
	map<string,int> mapIgnoradas; // map con las palabras ignoradas
	for (int i = 0; i < ignoradas.size(); ++i){
		mapIgnoradas[ignoradas[i]] = 1;
	}
	while(getline(cin,str)){ // input del titulo en minusculas
		string aux = str;
		transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		titulos.push_back(aux); // push al vector
	}
	for (int i = 0; i < titulos.size(); ++i){
		istringstream iss(titulos[i]); // descompone el titulo en sus palabras
		vector<string> vs;
		string aux;
		while(iss >> aux){
			vs.push_back(aux); // agrega cada palabra a un nuevo vector
		}
		for (int j = 0; j < vs.size(); ++j){
			if(mapIgnoradas.count(vs[j]) <= 0) { // si la palabra no es a ignorar
				string aux2 = vs[j];
				string final;
				transform(aux2.begin(), aux2.end(), aux2.begin(), ::toupper); // transforma a minusculas
				for (int k = 0; k < vs.size(); ++k){ // se vuelve a componer la palabra
					if(k != 0) final += " ";
					if(k == j) final+=aux2;
					else final+=vs[k];
				}
				vector_pair.push_back(make_pair(make_pair(aux2,j),make_pair(i,final))); // push del titulo con sus otras propiedades para sort
				//cout << final << endl;
			}		
		}		
	}

	sort(vector_pair.begin(),vector_pair.end(),ordenar); // sort del vector
	for (int i = 0; i < vector_pair.size(); ++i){ // print
		cout << vector_pair[i].second.second << endl;

	}
	return 0;
}