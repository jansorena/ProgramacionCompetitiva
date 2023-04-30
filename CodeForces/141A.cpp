#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2,s3,aux;
    cin >> s1 >> s2 >> s3;

    aux = s1+s2;
    sort(s3.begin(),s3.end());
    sort(aux.begin(),aux.end());
    (s3 == aux ? cout << "YES" : cout << "NO");

    return 0;
}
