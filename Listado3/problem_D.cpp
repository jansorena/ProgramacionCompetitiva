#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int count; cin >> count;
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<pair<string,int>> v;
    for (int i = 0; i < count; i++){
        string s; cin >> s;
        if(s == "insert"){
            int value; cin >> value;
            pq.push(value);
            v.push_back({s,value});
        }

        if(s == "getMin"){
            int value; cin >> value;
            if(!pq.empty() && pq.top() == value){
                v.push_back({s,value});
            }else{

                while(!pq.empty() && pq.top() < value){
                    pq.pop();
                    v.push_back({"removeMin",0});
                }
                if(pq.empty() || pq.top() != value) {
                    v.push_back({"insert",value});
                    pq.push(value);
                }
                v.push_back({s,value});
            }
        }

        if(s == "removeMin"){
            if(!pq.empty()) pq.pop();
            else{
                v.push_back({"insert",0});
            }
            v.push_back({"removeMin",0});
        }
    }

    cout << v.size() << endl;
    for(auto x : v){
        if(x.first == "removeMin") cout << x.first << endl;
        else cout << x.first << " " << x.second << endl;
    }
    return 0;
}
