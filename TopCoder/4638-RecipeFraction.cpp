#include<bits/stdc++.h>
using namespace std;

class RecipeFraction{
public: 
    double getFraction(vector<string> recipe, vector<string> ingredients){
        double total = 0.0, div = 0.0;
        unordered_map<string,int> map;
        for(auto x : recipe){
            istringstream iss (x);
            double val; iss >> val;
            string s; iss >> s;
            map[s] = val;
            total+=val;
        }
        for(auto x : ingredients){
            div+=map[x];
        }
        return div/total;
    }
};


int main(){
    vector<string> recipe = {"1 A","1 B","1 C","5 D","4 E"};
    vector<string> ingredients = {"A","E"};



    RecipeFraction rf;
    cout << rf.getFraction(recipe,ingredients);
    return 0;
}
