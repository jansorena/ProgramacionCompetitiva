#include <bits/stdc++.h>
using namespace std;
 
/*
struct que ordena la pq de mayor a menor por el primer elemento del par
y de menor a mayor en caso que que los primeros elementos sean iguales
*/
struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        if(a.first == b.first)
        	return a.second > b.second;
        else return a.first < b.first;
    }
};

int main(){
	int n, m, k; cin >> n >> m >> k;
	priority_queue<pair<int,int>,vector<pair<int,int>>,myComp> pq;
	priority_queue<int,vector<int>,greater<int>> sub;

	// se agrega al vector el elemento y su posicion
	for (int i = 0; i < n; ++i){
		int a; cin >> a;
		pq.push({a,i});
	}

	long long count = m*k;
	long long beauty = 0;

	// la beauty esta dada por los m*k mayores elementos
	// se agregan los elementos de la beauty a una nueva pq
	while(!pq.empty() && count--){
		beauty += pq.top().first;
		sub.push(pq.top().second);
		//cout << pq.top().second << " ";
		pq.pop();
	}

	cout << beauty << endl;

	// se divide el arreglo original en m subconjuntos y se imprime la
	// posicion correspondiente en el arreglo original
	long long aux = 1;
	while(!sub.empty()){
		if(aux == m*k) break;
		if(aux%m == 0) cout << sub.top()+1 << " ";
		sub.pop();
		aux++;
	}
	return 0;
}