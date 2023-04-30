#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
    cin.tie(0);

	string s; 
	map<string,int> m;
	string aux = "";
	while(getline(cin,s)){
		if(s == "") continue;

		for (int i = 0; i < s.length(); i++){
			s[i] = tolower(s[i]);
			if(s[i] >= 97 && s[i] <= 122) aux += s[i];
			else{
				if(s[i] == '-') aux += s[i];
				else{
					m[aux] = 0;
					aux = "";
				}
			}
		}

		if(aux[aux.length()-1] != '-'){
			m[aux] = 0;
			aux = "";
		}else aux.pop_back();
		
		
	}

	for (auto x : m) {
		if(x.first != "") cout << x.first << endl;
	}
	return 0;
}
