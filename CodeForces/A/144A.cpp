#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return a <= b ;
}

int main(){
    vector<int> v;
    int n; cin >> n;
    while(n--){
        int value; cin >> value;
        v.push_back(value);
    }
    int minPos = min_element(v.begin(),v.end(),comp) - v.begin();
    int maxPos = max_element(v.begin(),v.end()) - v.begin();

    int swaps = v.size() - minPos + maxPos - 1;
    if(maxPos > minPos) swaps--;

    cout << swaps << endl;
    return 0;
}
