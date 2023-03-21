#include<bits/stdc++.h>
using namespace std;

class Chooser{
public:
    int numSets(vector<int> param0, vector<int> param1, vector<int> param2){
        if(param0.size() == 0 || param1.size() == 0 || param2.size() == 0) return 0;
        int sets = param0.size()*param1.size()*param2.size();
        for(auto i : param0){
            for(auto j : param1){
                for(auto k : param2){
                    if(i+j+k > 75 | i+j+k < 60) sets--;
                }
            }
        }
        return sets;
    }
};

int main(){
    vector<int> param0 = {};
    vector<int> param1 = {15,25};
    vector<int> param2 = {30,35,40};

    Chooser *ch = new Chooser;
    cout << ch->numSets(param0,param1,param2);
    return 0;
}
