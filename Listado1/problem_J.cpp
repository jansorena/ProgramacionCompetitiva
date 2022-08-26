#include<bits/stdc++.h>
using namespace std;

class HangmanSolver{
public:
    string guess(string lettersGuessed, string revealed, vector<string> possibleAnswers){
        string ans = "";
        unordered_map<char,int> m;

        for (char c : lettersGuessed){
            m[c] = 0;
        }
        for(char c : revealed){
            if(c != '_')
                if(m.count(c) == 1) m.erase(c);
        }

        int sizeAns = revealed.size();
        int countAns = 0;

        for(string s : possibleAnswers){
            bool flag = true; 
            if(sizeAns == s.size()){
                for(int i = 0; i < sizeAns; i++){
                    
                    if(m.size() > 0 && m.count(s[i]) == 1) {
                        flag = false;
                        break;
                    }

                    if(revealed[i] == '_') continue;
                    else {
                        if(s[i] != revealed[i]){
                            flag = false;
                            break;
                        }  
                    }
                }
            }else flag = false;

            if(flag){
                ans = s;
                countAns++;
            }
               
        }
        if(countAns > 1) return "";
        else return ans;
    }
};


int main(){
    HangmanSolver h;

    string a = "a";
    string b = "_a_a_a";
    vector<string> v = {"banana", "cherry", "potato"};

    h.guess(a,b,v);

    return 0;
}