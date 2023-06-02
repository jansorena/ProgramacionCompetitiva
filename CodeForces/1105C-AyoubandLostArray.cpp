// codigo conseguido de https://blog.csdn.net/wynswd/article/details/90244817

#include<bits/stdc++.h>
using namespace std;
long long yy[200005][5];
long long kk = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

	int n, l, r;
	cin >> n >> l >> r;
	
	memset(yy,0,sizeof(yy));
	long long a,b,c;
	a=b=c=(r-l+1)/3;


    // calcula el número de elementos con residuo 0, 1 y 2 % 3 en el rango l,r
    // y se almacenan en las variables a, b y c

	for(int i = 0;i < (r-l+1)%3; i++){
	   if((i+l)%3 == 0) a++;
	   if((i+l)%3 == 1) b++;
	   if((i+l)%3 == 2) c++;
	}

    // se utiliza programacion dinamica para el total
    // en cada iteracion se calcula el número de formas de formar la suma módulo 3 para los 
    // residuos 0, 1 y 2 utilizando los valores anteriores almacenados
	yy[1][0] = a , yy[1][1] = b , yy[1][2] = c;
	for(int i = 2; i <= n; i++){
	   yy[i][0] = (yy[i-1][0]*a%kk + yy[i-1][1]*c%kk + yy[i-1][2]*b%kk)%kk;
	   yy[i][1] = (yy[i-1][0]*b%kk + yy[i-1][1]*a%kk + yy[i-1][2]*c%kk)%kk;
	   yy[i][2] = (yy[i-1][0]*c%kk + yy[i-1][1]*b%kk + yy[i-1][2]*a%kk)%kk;
	}
	//impresion
    cout << yy[n][0];
	
	return 0;
}