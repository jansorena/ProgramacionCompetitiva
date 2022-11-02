#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	map<string,string> ip;

	for (int i = 0; i < n; ++i){
		string s1,s2; cin >> s1 >> s2;
		ip[s2] = s1;
	}

	for (int i = 0; i < m; ++i){
		string s1,s2; cin >> s1 >> s2;
		s2.pop_back();
		cout << s1 << " " << s2 << "; #" << ip[s2] << endl;
	}
	return 0;
}