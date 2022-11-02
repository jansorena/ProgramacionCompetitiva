#include <bits/stdc++.h>
using namespace std;

struct comp { 
    bool operator()(const pair<int,int>&mypair,const int& n) { 
        if(mypair.first < n) return 1;
        return 0;
    }

    bool operator()(const int& n,const pair<int,int>& mypair) { 
        if(n < mypair.first)return 1;
        return 0;
    } 
}; 

int main(){
	//variables
	int n, m;
	int s,r;
	cin >> n >> m;
	map<int,int> subjects;
	priority_queue<int,vector<int>,greater<int>> pq;
	vector<pair<int,int>> v;

	// algoritmo
	for (int i = 0; i < n; ++i){
		cin >> s >> r;
		v.push_back({s,r});
		subjects[s]++;
	}

	for(auto x : subjects){
		pq.push(x.second);
	}

	sort(v.begin(),v.end());
	int sum = 0;

	cout << "---" << endl;
	for(auto x : subjects){
		int value = x.second;
		auto position = upper_bound(v.begin(),v.end(),value,comp());
		cout << position - v.begin() << endl;
	}


	return 0;
}