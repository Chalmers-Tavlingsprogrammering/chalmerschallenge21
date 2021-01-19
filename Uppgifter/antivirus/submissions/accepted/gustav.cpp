#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
#define sz(x) ((int)(x).size())
constexpr int inf = 0x3f3f3f3f;

int main(){
    int n;
    cin >> n;
    vl a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vi b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
        b[i]--;
    }
    //etc etc
    cout << 0 << endl;
}
