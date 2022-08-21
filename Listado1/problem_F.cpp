#include<bits/stdc++.h>
using namespace std;

class WordFindPuzzle{
private:
    int solucion = 0;
    vector<string> board;
public:
    void busqueda(int dir, string word, int pos, int i, int j){
        solucion++;
    }

    int solveWordFindPuzzle(vector<string> words, vector <string> board){
        this->board = board;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].length(); j++){
                for(auto x : words){
                    if(x[0] == board[i][j]){
                        if(j < board[0].length()-1) busqueda(1,x,1,i,j++);
                        if(i < board.size()-1) busqueda(2,x,1,i++,j);
                        if(j > 0) busqueda(3,x,1,i,j--);
                        if(i > 0) busqueda(4,x,1,i--,j);
                    }
                }
            }
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