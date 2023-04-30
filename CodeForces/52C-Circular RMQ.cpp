#include <bits/stdc++.h>
using namespace std;

// template lazy segmented tree
// construir arbol segmentado
void buildTree(long long *tree,int *a,int index,int s,int e){
	if(s>e)
		return;
	if(s==e){
		tree[index]=a[s];
		return;
	}
	int m = (s+e)/2;
	buildTree(tree,a,2*index,s,m);
	buildTree(tree,a,2*index+1,m+1,e);
	tree[index]= min(tree[2*index],tree[2*index+1]);
	return;
}

// actualizar rango usando propagacion lazy
void updateRange(long long *tree,long long *lazy,int index,int s,int e,int rs,int re,int inc){
	if(lazy[index]!=0){
		tree[index] += lazy[index];
		if(s!=e){
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		lazy[index]=0;
	}

	if(s>e || s>re || e<rs) return;
		
	if(s>=rs && e<=re){
		tree[index] += inc;
		if(s!=e){
			lazy[2*index]+=inc;
			lazy[2*index+1] +=inc;
		}
		return;
	}

	long long m = (s+e)/2;
	updateRange(tree,lazy,2*index,s,m,rs,re,inc);
	updateRange(tree,lazy,2*index+1,m+1,e,rs,re,inc);
	tree[index] = min(tree[2*index],tree[2*index+1]);
}

// min query 
long long query(long long *tree,long long *lazy,int index,int s,int e,int rs,int re){
	if(lazy[index]!=0){
		tree[index] += lazy[index];
		if(s!=e){
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		lazy[index]=0;
	}

	if(s>e || s>re || e<rs) return LLONG_MAX;
		
	if(s>=rs && e<=re) return tree[index];
		
	long long m= (s+e)/2;
	long long left=query(tree,lazy,2*index,s,m,rs,re);
	long long right = query(tree,lazy,2*index+1,m+1,e,rs,re);

	return min(left,right);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 	int n; cin >> n;
 	int array[n];

 	for (int i = 0; i < n; ++i){
 		long long value; cin >> value;
 		array[i] = value;
 	}

 	//arbol binario segmentado
 	long long *tree = new long long[4*n+1]();
 	long long *lazy = new long long[4*n+1]();
 	int index = 1;													//index of 1st node
    int s = 0, e = n-1;

    buildTree(tree,array,index,s,e);

    int m; cin >> m;
    cin.ignore();

    for (int i = 0; i < m; ++i){
    	string op;
    	getline(cin,op);
    	int m1,m2,m3;
    	stringstream ss(op);
    	if (ss >> m1 >> m2 && !(ss >> m3)){
    		if(m1 <= m2){
    			cout<<query(tree,lazy,index,s,e,m1,m2)<<endl;
    		}else{ // busqueda circular, menor de ambos lados
    			long long min1 = query(tree,lazy,index,s,e,m1,n);
    			long long min2 = query(tree,lazy,index,s,e,0,m2);
    			cout << min(min1,min2) << endl;
    		}

    	}else{
    		ss >> m1 >> m2 >> m3;
    		if(m2 < m1){ //actualizar de manera circular lado der e izq
    			updateRange(tree,lazy,index,s,e,m1,n,m3);
    			updateRange(tree,lazy,index,s,e,0,m2,m3);
    		}else{
    			updateRange(tree,lazy,index,s,e,m1,m2,m3);
    		}
    	}
    }
	return 0;
}