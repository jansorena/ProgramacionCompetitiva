#include<bits/stdc++.h>
using namespace std;

class HangmanSolver{
public:
    string guess(string lettersGuessed, string revealed, vector<string> possibleAnswers){
        string ans = "";
        unordered_map<char,int> m;
        unordered_map<char,int> m2;
        int numSolutions = 0;

        for(auto c : lettersGuessed) {
            m[c] = 0;
        }
        for(auto c : revealed){
            if(m.count(c)) m.erase(c);
            if(c != '_') m2[c] = 0;
        }

        for(auto s : possibleAnswers){
            bool flag = true;
            for(int i = 0; i < s.length(); i++){
                if(m.count(s[i]) || (m2.count(s[i]) && revealed[i] == '_')) {
                    flag = false;
                    break;
                }
                if(s[i] == revealed[i] || revealed[i] == '_') continue; 
                    
                
                else{
                    flag = false;
                    break;
                } 
            }
            if(flag){
                ans = s;
                numSolutions++;
            }
        };

        if(numSolutions > 1) return "";
        return ans;
    }
};


int main(){
    HangmanSolver h;

    string a = "a";
    string b = "_a___a";
    vector<string> v = {"canada", "rwanda", "potato","camera","lambda","saliva"};

    cout << h.guess(a,b,v);
    

    return 0;
}