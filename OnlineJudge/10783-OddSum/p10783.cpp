#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){

	int testCases;
	cin >> testCases;
	int sumas[testCases];

	// calcular la suma de los impares en los intervalos
	for (int i = 0; i < testCases; i++) {
		int a,b;
		sumas[i] = 0;
		cin >> a >> b;
		for (int j = a; j <= b; j++) {
			if (j%2!=0) sumas[i] += j;
		}
	}

	// print

	for (int i = 0; i < testCases; i++) {
		cout << "Case " << i + 1 << ": " << sumas[i] << endl;
	}


	return 0;
}