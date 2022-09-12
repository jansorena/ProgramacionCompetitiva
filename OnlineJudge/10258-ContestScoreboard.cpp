#include <bits/stdc++.h>
using namespace std;

struct Concursante{ // struct para cada concursante
	int idConcursante = 0;
	int problemasResueltos = 0;
	int tiempo = 0;
	bool participacion = false;
	map <int,bool> isCorrecto; // mapa para cada problema si esta resuelto
	map <int,int> numIncorrectos; // mapa con los min de penalizacion para cada problema
};

// funciones de comparacion. problemas resueltos -> tiempo penalizacion -> numero del concursante
bool comparacion(const Concursante &c1, const Concursante &c2){ 
   	if(c1.problemasResueltos > c2.problemasResueltos) return true;
   	if(c1.problemasResueltos < c2.problemasResueltos) return false;
   	
   	if(c1.tiempo < c2.tiempo) return true;
   	if(c1.tiempo > c2.tiempo) return false;

   	if(c1.idConcursante < c2.idConcursante) return true;
   	if(c1.idConcursante > c2.idConcursante) return false;

   	return false;
}

int main(){
	int casos; cin >> casos;
	bool primero = true;

	cin.ignore(); // ignorar las primeras lineas vacias
	cin.ignore();

	for (int i = 0; i < casos; ++i){
		if(!primero) cout << endl;
		primero = false;

		int numero,problema,tiempo;
		string resultado, str;
		Concursante array[101]; // array con los 100 concursantes
		//map <int,Concursante> m;

		for (int j = 1; j < 101; ++j){ // se agrega cada struct al array
			Concursante co;
			co.idConcursante = j;
			array[j] = co;
		}

		while(getline(cin,str)){
			if(str.size() == 0) break;
			istringstream iss(str); // dividimos el string en las distintas variables

			iss >> numero >> problema >> tiempo >> resultado;
			//cout << numero << problema << tiempo << resultado << endl;
			
			Concursante co = array[numero];

			if(resultado == "C"){ // Si el resultado es correcto
				if(co.isCorrecto.count(problema) <= 0){ // si el problema no esta resuelto aun se agrega el tiempo y el contador
					co.problemasResueltos++; // de problemas resueltos
					co.tiempo+=tiempo; // 
				} // si ya esta resuelto sigue el condicional
				co.participacion = true;
				co.isCorrecto[problema] = true; // marcamos el problema como resuelto
			}else{
				if(resultado == "I"){
				if(co.isCorrecto.count(problema) <= 0) co.numIncorrectos[problema]+=20; // si el problema no esta resuelto agregamos la penalizacion
				co.participacion = true;
				}else{
					co.participacion = true; // cualquiere otro resultado lo marcamos para que aparezca en el print
				}
			}
			array[numero] = co;
		}

		vector<Concursante> v;

		for(int k = 1; k < 101; ++k){
			for (int l = 1; l < 10; ++l){ // si el problema esta resuelto agregamos el tiempo de penalizacion correspondiente
				if (array[k].isCorrecto.count(l) > 0){
    				array[k].tiempo+=array[k].numIncorrectos[l];
				}					
			}

			if(array[k].participacion){ // agregamos los struct al vector para hacer sort
				v.push_back(array[k]);
			}
		}

		sort(v.begin(),v.end(),comparacion); // sort del vector
		for(int k = 0; k < v.size(); ++k){ // impresion
			cout << v[k].idConcursante << " " << v[k].problemasResueltos << " " << v[k].tiempo << endl;
		}

	}

	return 0;
}