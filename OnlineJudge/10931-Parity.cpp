#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> v;

  while(1){
    int input;
    cin >> input;
    if(input == 0) break;
    else v.push_back(input);
  }

  int binario[31];

  for (int i = 0; i < v.size(); i++) {
    int countBinario = 0, countParidad = 0;
    while(v[i] > 0){
      binario[countBinario] = v[i]%2;
      if(binario[countBinario] == 1) countParidad++;
      v[i]/=2;
      countBinario++;
    }
    cout << "The parity of ";
    for (int i = countBinario-1; i >= 0; i--) {
      cout << binario[i];
    }
    cout << " is " << countParidad << " (mod 2)." << endl;
  }

  return 0;
}

