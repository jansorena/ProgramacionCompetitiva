#include <bits/stdc++.h>
using namespace std;

int main(){
    int count;
    while(cin >> count){ // entrada de los datos
    	int num, absValue;
    	bool flag = true;
    	vector<int> v;
    	bool arrBool[3000] = {false}; // vector para marcar las distancias. Si el valor se repite no es jolly jumper
    	for (int i = 0; i < count; ++i){ // insertar los datos al vector
    		cin >> num;
    		v.push_back(num);
    	}
    	for (int i = 0; i < v.size()-1; ++i){
    		absValue = abs(v[i]-v[i+1]); // distancia absoluta entre dos numeros consecutivos
    		if(absValue > count-1 || absValue == 0 || arrBool[absValue]){
    			flag = false; // si la distancia es 0, mayor a 1, o la distancia esta repetida no es jolly jumper
    			break;
    		}
    		arrBool[absValue] = true; // marcamos la distancia en el arreglo
    	}
    	if(flag) cout << "Jolly" << endl; // impresion
    	else cout << "Not jolly" << endl;
    }
	return 0;
}
