#include <bits/stdc++.h>
using namespace std;

class TVRemoteText{

vector<string> v = {"ABCDEFG",
                    "HIJKLMN",
                    "OPQRSTU",
                    "VWXYZ12",
                    "3456789",
                    "0$.,-!?",
                    ":/+()*@", 
                    "&%#=<> "};
public:
    int numPresses(string text){
        int posX = 0, posY = 0, distancia = 1;
        for(char c : text){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 7; j++){
                    if(v[i][j] == c){
                        distancia+= abs(i-posX)+abs(j-posY)+1;
                        posX = i;
                        posY = j;
                    }
                }
            }        
        }
        cout << distancia << endl;
        return distancia;
    }
};


int main(){
    TVRemoteText t;
    t.numPresses("2B+-2B,THAT=? 3177 $H4K5P3R3");
    return 0;
}