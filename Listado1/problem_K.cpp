#include <bits/stdc++.h>
using namespace std;

class AdvertisingAgency{
public:
    int numberOfRejections(vector<int> requests){
        unordered_map<int,int> map;

        for(auto x : requests) map[x] = 0;

        return requests.size() - map.size();
    }
};


int main(){
    AdvertisingAgency aa;
    cout << aa.numberOfRejections({100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100
});
    return 0;
}