#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;

class TextColumns{

public:
    vs formatText(vs text){
        vs paragraph;
        int ancho = text[0].length();
        int largo = text.size();
        string s,aux;

        for (int i = 0; i < largo; i++){
            for (int j = 0; j < ancho; j++){
                s+=text[i][j];
                aux+=text[i][j];
                if(aux == "   "){
                    paragraph.push_back(s);
                }
            }
            
        }
        

        return paragraph;
    }
};


int main(){

    return 0;
}