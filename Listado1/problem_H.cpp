#include<bits/stdc++.h>
using namespace std;

class Yllion{
    unordered_map<string,int> m = {
        {"hundred",1},
        {"myriad",2},
        {"myllion",3},
        {"byllion",4},
        {"tryllion",5},
        {"quadryllion",6},
        {"quintyllion",7},
        {"sextyllion",8},
        {"septyllion",9},
        {"octyllion",10},
        {"nonyllion",11},
        {"decyllion",12}
    };

    vector<string> v = {
        "","hundred","myriad","myllion","byllion","tryllion","quadryllion",
        "quintyllion","sextyllion","septyllion","octyllion","nonyllion",
        "decyllion"
    };
    
public:
    string getPower(string a, string b){
        string s, res = a + " " + b, word;
        int value = 0, aux = 1;
        istringstream iss(res);
        while(iss >> s) { 
            if(s == "ten") value++;
            else if(s != "one") value+= pow(2,m[s]);
        }
        
        if(value % 2 != 0) {
            word+="ten ";
            value--;
        }
        else word+="one ";
        value/=2;

        while(value > 0){
            if(value%2 != 0) word+=v[aux]+" ";
            value/=2;
            aux++;
        };
        word.pop_back();  
        return word;
    }
};



int main(){

    Yllion y;
    y.getPower("ten","ten hundred myriad myllion byllion tryllion quadryllion quintyllion sextyllion septyllion octyllion nonyllion");
    return 0;
}