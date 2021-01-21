#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(char& c : a){
        if(c == '2') c = '5';
        else if(c == '5') c = '2';
    }
    for(char& c : b){
        if(c == '2') c = '5';
        else if(c == '5') c = '2';
    }
    if(a.size() > b.size() || (a.size() == b.size() && a > b)){
        cout << 1 << endl;
    }
    else cout << 2 << endl;
}
