#include <bits/stdc++.h>
using namespace std;

struct Equipo { // struct para ordenar los equipos
	string nombre;
	int puntos = 0;
	int games = 0;
	int golesFavor = 0;
	int golesContra = 0;
	int deltagoles = 0;
	int numero = 0;
	int indice;
};
// funcion para ordenar
bool ordenar(const Equipo &e1, const Equipo &e2){ 
    if (e1.puntos > e2.puntos) return true; // ordenar descendente por puntos
    if (e1.puntos < e2.puntos) return false;

    if (e1.deltagoles > e2.deltagoles) return true; // si puntos son iguales
    if (e1.deltagoles < e2.deltagoles) return false; // ordenar descendente por diferencia goles

    if (e1.golesFavor > e2.golesFavor) return true; // si diferencia goles son iguales
    if (e1.golesFavor < e2.golesFavor) return false; // ordenar descendente por goles a favor

    string aux1 = e1.nombre; // strings con los nombres del equipo
	string aux2 = e2.nombre;

	transform(aux1.begin(), aux1.end(), aux1.begin(), ::tolower); // transformar a minusculas para
	transform(aux2.begin(), aux2.end(), aux2.begin(), ::tolower); // comparar

	if(aux1 < aux2) return true; // si goles a favor son iguales ordenar alfabeticamente
	if(aux1 > aux2) return false;

	return e1.indice < e2.indice; // si nombre es igual ordenar por ingreso del equipo
}

int main(){
	bool primero = true;
	while(true){
		int T,G;
		cin >> T >> G;
		if(T == 0 && G == 0) break;

		if(!primero) cout << endl;
		primero = false;

		map <string,Equipo> m; // agregamos las struct a un mapa no ordenado
		vector<Equipo> v; // vector para ordenar los equipos

		for (int i = 0; i < T; ++i){ // ingreso de los equipos al map
			string nombre; cin >> nombre;
			Equipo eq;
			eq.nombre = nombre;
			eq.indice = i;
			m[nombre] = eq;
		}

		for (int i = 0; i < G; ++i){ // Ingreso de los datos de los partidos
			string equipo1,equipo2,guion; // calculos de las distintas propiedades
			int score1, score2;
			cin >> equipo1 >> score1 >> guion >> score2 >> equipo2;
			
			if(m.count(equipo1) > 0){ // si el equipo existe en el map
				m[equipo1].games++;
				if(score1 > score2) m[equipo1].puntos+=3;
				if(score1 == score2) m[equipo1].puntos+=1;
				m[equipo1].golesFavor += score1;
				m[equipo1].golesContra += score2;
				m[equipo1].deltagoles += (score1-score2);
			}
			
			if(m.count(equipo2) > 0){ // si el equipo existe en el map
				m[equipo2].games++;
				if(score2 > score1) m[equipo2].puntos+=3;
				if(score1 == score2) m[equipo2].puntos+=1;
				m[equipo2].golesFavor += score2;
				m[equipo2].golesContra += score1;
				m[equipo2].deltagoles += (score2-score1);
			}		
		}

		for (auto x : m){ // agregar los equipos a un vector para sort
			v.push_back(x.second);	
		}

		// sort. puntos -> diferencia goles -> goles a favor -> alfabetico -> indice.
		sort(v.begin(),v.end(),ordenar);

		int posicion = 1;
		int puntos, deltagoles, golesFavor;

		for (int i = 0; i < v.size(); ++i){ // impresion de acuerdo al output requerido
			Equipo temp = v[i];

			if(posicion == 1) cout << setw(2) << posicion << "."; // siempre imprimimos la primera posicion
			else{
				if(puntos == temp.puntos && deltagoles == temp.deltagoles && golesFavor == temp.golesFavor){
					cout << setw(3) << "   "; // impresion si los equipos tienen la misma posicion
				}else cout << setw(2) << posicion << "."; // si no tienen la misma posicion
			}

			cout << setw(16) << temp.nombre << setw(4) << temp.puntos<< setw(4) << temp.games;
			cout << setw(4) << temp.golesFavor << setw(4) << temp.golesContra << setw(4) << temp.deltagoles << " ";		
			
			double porcentajePuntos = (double)temp.puntos/(double)(temp.games*3);
			
			if(temp.games != 0){
				printf("%6.2lf\n",porcentajePuntos*100);
			}	
			else cout << setw(6) << "N/A" << endl;
			
			posicion++;
			// guardamos las variables para compararlos con el siguiente equipo
			puntos = temp.puntos; deltagoles = temp.deltagoles; golesFavor = temp.golesFavor;
		}
	}
	return 0;
}