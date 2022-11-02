#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	map<string,int> m;
	while(getline(cin,s)){
		if(s != ""){
			for(int i = 0; i < s.length(); ++i) 
				s[i] = tolower(s[i]);
			//cout << s << endl;
			string aux = "";
			for (int i = 0; i < s.length(); ++i){
				if(s[i] == ' ') {
					m[aux] = 0;
					aux = "";
				}else if(s[i] > 96 && s[i] < 123){
					aux += s[i];
				} 
			}

			if(aux!= "") {
				m[aux] = 0;
			}
		}
	}

	for(auto x : m) cout << x.first << endl;

	return 0;
}