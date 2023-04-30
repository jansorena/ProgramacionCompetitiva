// codigo conseguido de https://vjudge.net/solution/13276812

#include <bits/stdc++.h> 
#define all(a) (a).begin(), (a).end()
using namespace std;

typedef vector <int>:: iterator iter;

// defincion de la estructura wavelet tree
struct WaveletTree {
	WaveletTree *left = 0, *right = 0; // puntero a los arboles hijos
	int lo, hi, mid; // rango de indices
	iter B, E; // comienzo y final del rango de valores
	vector <int> ct; // almacena valores menores a mid

	WaveletTree () {}

	// construccion del arbol
	WaveletTree(iter b, iter e, int lo_, int hi_){ 
		B = b, E = e;
		lo = lo_, hi = hi_;
		mid = (lo + hi) >> 1;
		if (lo == hi or b >= e) return; 
		ct.reserve(e - b +1);
		ct.emplace_back(0);
		for (auto it = b; it != e; it++)
			ct.emplace_back(ct.back() + ((*it) <= mid));

		iter pivot = stable_partition(b, e, [=] (const int& i) { return i <= mid; } );
		left = new WaveletTree(b, pivot, lo, mid);
		right = new WaveletTree (pivot, e, mid + 1, hi);
	}

	~WaveletTree() { 
		delete left;
		delete right;
	}

	// encontrar el k-esimo elemento en el rango dado
	int kth(int a, int b, int k){ 
		if (a > b) return -1; // rango invalido
		if (lo == hi) return lo; // hoja
		int inLeft = ct[b] - ct[a - 1]; // elementos en el arbol izq
		if (k <= inLeft) return left -> kth(ct[a - 1] + 1, ct[b], k); // si k esta en el arbol izq
		return right -> kth(a - ct[a - 1], b - ct[b], k - inLeft) ; // en otro caso k esta en el arbol derecho
	}
};

int N, Q, sigma;
vector <int> arr, A; 
map <pair <int, int>, int> ind;
unordered_map <int, int> mp, ct;
WaveletTree *tree;

// reduce la cantidad de elemenots distintos en vector arr
void compress() {
	sort (all(A));
	mp[A[0]] = ++sigma; 

	for (int i = 1; i < N; i++) { // mapea cada elemento unico de A
		if (A[i] != A[i - 1]) sigma++;
		mp[A[i]] = sigma;
	}

	for (int i = 0; 1 < N; i++) { // cuenta la cantidad de aparacciones en arr
		arr[i] = mp[arr [i]];
		ct[arr[i]] ++;
		ind [{arr[i], ct[arr[i]]}] = i; // asocia cada par con el indice en arr de la kesima aparicion
	}
}

void read(){ // lectura del input
	scanf("%d %d", &N, &Q);
	arr.resize (N);
	A.resize (N);
	for (int i = 0; i < N; i++) {
		scanf ("%d", &arr[i]);
		A[i] = arr [i]; 
	}
}

int main(){
	read();
	compress();
	tree = new WaveletTree(all(arr), 1, sigma);
	while (Q--) {
		int k, i, l, d;
		scanf ("%d %d %d", &k, &i, &l);
		d = tree -> kth(1, i + 1, k); // responder a cada query
		if (ind.find({d, l}) == ind.end ()) puts ("-1");
		else printf ("%d\n", ind[{d, l}]); 
	}
	delete tree;
	return (0);
}
