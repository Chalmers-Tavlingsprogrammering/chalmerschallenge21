#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
constexpr int inf = 0x3f3f3f3f;


int main(){
    ll n;
    cin >> n;
    vl a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    ll prev = 0;
    for(int i = 0; i < n; i++){
        ll d = abs(a[i]-prev);
        ans += __builtin_popcount(d^(3*d));
        prev = a[i];
    }
    
    cout << ans << endl;
}
