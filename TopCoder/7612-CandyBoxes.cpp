#include<bits/stdc++.h>
using namespace std;

class CandyBoxes{
public:
    int remainingCandies(vector<int> &candies){
        auto max = max_element(candies.begin(),candies.end());
        int posMax = max - candies.begin();
        auto min = min_element(candies.begin(),candies.end());
        
        if(*max == *min) return *max;
        else{
            candies[posMax] -= *min;
            return remainingCandies(candies);
        }
    }
};

int main(){
    vector<int> v = {7, 21, 14};
    CandyBoxes *cb = new CandyBoxes;
    cout << cb->remainingCandies(v);
    return 0;
}
