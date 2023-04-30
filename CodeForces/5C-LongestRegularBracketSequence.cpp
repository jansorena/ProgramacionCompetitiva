#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    string s; cin >> s;
    stack<int> stk;
    
    priority_queue<int,vector<int>,greater<int>> pq;

    for (int i = 0; i < s.length(); i++){
        if(s[i] == '(') stk.push(i);
        else{
            if(!stk.empty()){
                pq.push(i);
                pq.push(stk.top());
                stk.pop();
            }
        }
    }
    
    map<int,int,greater<int>> m;
    int lastValue = INT_MAX;
    int length = 0;

    while(!pq.empty()){
        int aux = pq.top();
        if(aux - lastValue > 1){
            m[length]++;
            length = 1;
            pq.pop();
        }else{
            pq.pop();
            length++;
        }
        lastValue = aux;
    }
    if(length != 1)  m[length]++;

    if(m.begin()->first == 0) cout << 0 << " " << 1;
    else cout << m.begin()->first << " " << m.begin()->second;
    return 0;
}
