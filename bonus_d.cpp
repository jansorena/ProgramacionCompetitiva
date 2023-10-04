#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n,h,w; cin >> n >> h >> w;

  for (int i = 0; i < n; ++i){
  	for (int j = 0; j < 2; ++j){
  		char c; cin >> c;
  		if(c == 'Y' || h == 0 || w == 0){
  			if(j == 0){
  				h--;
  				w++;
  			}else{
  				h++;
  				w--;
  			}
  			cout << "Y" << " ";
  		}else{
  			cout << "N" << " ";
  		}
  	}
  	cout << endl;
  }

  return 0;
}