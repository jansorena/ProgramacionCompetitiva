#include <bits/stdc++.h>
using namespace std;

int main(){
	string input;
	int sum = 0;
	int bestSum = 0;
	vector<int> v;

	while(getline(cin,input)){
		istringstream iss(input);
		int value;
		iss >> value;
		if(input == ""){
			//cout << bestSum << endl;
			if(sum >= bestSum) bestSum = sum;
			v.push_back(sum);
			sum = 0;		
		}
		else
			sum+=value;
	}

	sort(v.begin(),v.end(),greater<int>());

	int ans = 0;

	for (int i = 0; i < 3; ++i){
		ans += v[i];
	}

	cout << ans << endl;

	return 0;
}