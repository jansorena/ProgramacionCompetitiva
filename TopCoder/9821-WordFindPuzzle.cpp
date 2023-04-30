#include<bits/stdc++.h>
using namespace std;

class WordFindPuzzle{
private:
    int solucion = 0;
    vector<string> board;
    unordered_map<string,pair<bool,bool>> map;
public:
    void busqueda(int dir, string word, int pos, int i, int j){
        if(pos == word.length()){
            if(dir == 1 || dir == 3) map[word].first = true;
            else map[word].second = true;
        }
        else{
            if(dir == 1 && j<board[0].length() && board[i][j] == word[pos]) 
                busqueda(1,word,pos+1,i,j+1);
            if(dir == 2 && i<board.size() && board[i][j] == word[pos]) 
                busqueda(2,word,pos+1,i+1,j);
            if(dir == 3 && j>=0 && board[i][j] == word[pos]) 
                busqueda(3,word,pos+1,i,j-1);
            if(dir == 4 && i>=0 && board[i][j] == word[pos]) 
                busqueda(4,word,pos+1,i-1,j);
        }
    }

    int solveWordFindPuzzle(vector<string> words, vector <string> board){
        this->board = board;
        int ancho = board[0].length();
        int largo = board.size();
        for(int i = 0; i < largo; i++){
            for(int j = 0; j < ancho; j++){
                for(auto x : words){
                    if(x[0] == board[i][j]){
                        if(j<ancho) busqueda(1,x,0,i,j);
                        if(i<largo) busqueda(2,x,0,i,j);
                        if(j>=0) busqueda(3,x,0,i,j);
                        if(i>=0) busqueda(4,x,0,i,j);
                    }
                }
            }
        }
        for(auto x : map){
            if (x.second.first && x.second.second) solucion++;
        }       
        return solucion;
    }
};

int main(){
    vector<string> words = {"park", "kim", "lee", "choi"};
    vector<string> board = {"lxamal",
 "alkime",
 "parkpe",
 "lyaeel",
 "aypepl"};
    WordFindPuzzle wf;
    cout << wf.solveWordFindPuzzle(words,board);
    return 0;
}