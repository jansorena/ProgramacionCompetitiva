#include<bits/stdc++.h>
using namespace std;

class TextColumns{
public:
	vector<string> formatText(vector<string> text){
		int largo = text[0].length();
		int ancho = text.size();

		vector<string> ans;

		vector<int> espacios(largo,0);
		// agregar la cantidad de palabras al vector
		for (int i = 0; i < ancho; ++i){
			for (int j = 0; j < largo; ++j){
				if(text[i][j] != ' ') espacios[j]++;
			}
		}

		map<int,int> m;

		bool flagInicio = true;
		int contador = 0;
		int inicio, fin;

		// marcar los inicios y terminos de cada columna
		// se agregan a un mapa 
		for (int i = 0; i < largo; ++i){
			if(espacios[i] != 0 && flagInicio) {
				inicio = i;
				flagInicio = false;
			}

			if(espacios[i] == 0) contador++;
			else contador = 0;

			if(contador == 3 && !flagInicio){
				m[inicio] = i-3;
				flagInicio = true;
				contador = 0;
			}

			if(i == largo -1 && !flagInicio) m[inicio] = i;
		}

		string temp;
		// extraen las palabras de cada columna y se marcan los cambios de
		// parrafos
		for(auto x : m){
			string r,aux;
			string aux2 (x.second-x.first+1,' ');
			bool flag = false;
			for (int i = 0; i < ancho; i++){
				r = text[i].substr(x.first,x.second-x.first+1);
				
				if(r != aux2 && aux == aux2 && flag) {
					ans.push_back(temp);
					temp = "";
					flag = false;
				}
				aux = r;
				if(r!=aux2) {
					temp+=" "+r;
					flag = true;;
				}		
			}
		}
		ans.push_back(temp);
		vector<string> ans2;
		
		// eliminan los espacios y las lineas en blanco
		// se copia a un nuevo vector
		for(auto x : ans){
			string aux3(x.length(),' ');
			string temp2,temp3;
			if(x == aux3) continue;
			else{
				istringstream iss(x);
				while(iss >> temp2)
				{
					temp3 += temp2 + ' ';
				}
			}
			temp3.pop_back();
			ans2.push_back(temp3);
		}
		return ans2;
	}
};


int main(){
	TextColumns tc;
	vector<string> text =  {"  This is       put  it      that       ",
 " a text          all       is           ",
 "in  several    together      nicely     ",
 "columns.       into  a      formatted.  ",
 "               single                   ",
 " Your  job        text                  ",
 "is     to                   Good luck!  "};

	vector<string> ans = tc.formatText(text);

	return 0;
}