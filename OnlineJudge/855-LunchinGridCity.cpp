#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    for (int i = 0; i < T; ++i){
        int S,A,F;
        cin >> S >> A >> F;
        vector<int> streets; // vector para las calles
        vector<int> avenues; // vector para las avenidas
        for (int i = 0; i < F; ++i){ // insertar a los vectores
            int street, avenue;
            cin >> street >> avenue;
            streets.push_back(street);
            avenues.push_back(avenue);
        }
        sort(streets.begin(),streets.end()); // ordenar ambos vectores
        sort(avenues.begin(),avenues.end());
        int bestStreet, bestAvenue;

        if(F%2 == 0){ // la menor distancia corresponde a la mediana de ambos vectores
            bestStreet = streets[F/2-1];
            bestAvenue = avenues[F/2-1];
        }else{
            bestStreet = streets[F/2];
            bestAvenue = avenues[F/2];
        }
        printf("(Street: %d, Avenue: %d)\n", bestStreet,bestAvenue); // impresion
    }
	return 0;
}
