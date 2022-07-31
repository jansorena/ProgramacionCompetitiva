#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int total;
  cin >> total;

  int num[total];
  for (int i = 0; i < total; i++) {
    string palabra;
    cin >> palabra;
    int con = 0;
    if(palabra.length() == 3){
      if(palabra[0] == 'o') con++;
      if(palabra[1] == 'n') con++;
      if(palabra[2] == 'e') con++;
      if (con >=2) num[i] = 1;
      else num[i] = 2;
    }else{
      num[i] = 3;
    }
  }

  for (int i = 0; i < total; i++) {
    cout << num[i] << endl;
  }

  return 0;
}