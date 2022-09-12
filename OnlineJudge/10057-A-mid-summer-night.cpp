#include <bits/stdc++.h>
using namespace std;

int funcion(vector<int> v, int A){
	int suma = 0;
	for (int i = 0; i < v.size(); ++i){
		suma+=abs(v[i]-A);
	}
	return suma;
}

int binarySearch(vector<int> v, vector<int> v2,int menorSuma, int searchFirst){
    int low = 0, high = v.size() - 1;
    int result = -1;
 
    while (low <= high){
        int mid = (low + high)/2;
        if (menorSuma == v2[mid]) {
            result = mid;
            if (searchFirst == 1) high = mid - 1;
            else low = mid + 1;
        }
        else high = mid - 1;
    }
    //cout << result << endl;
    return result;
    
}

int main(){
	int count;
	while(cin >> count){
		vector<int> v,v2;
		for (int i = 0; i < count; ++i){
			int x; cin >> x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());

		for (int i = 0; i < v.size(); ++i){
			v2.push_back(funcion(v,v[i]));
		}
		//sort(v2.begin(),v2.end());

		int mediana = v[(count-1)/2];
		int menorSuma = funcion(v,mediana);

		int izquierda = binarySearch(v, v2, menorSuma, 1);
 		int derecha = binarySearch(v, v2, menorSuma, 0);

		int total = v[count/2]-v[(count-1)/2]+1;

		cout << mediana << " " << derecha-izquierda+1 << " " << total << endl;
	}
	return 0;
}