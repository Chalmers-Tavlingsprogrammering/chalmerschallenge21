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
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    vl b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    ll ans = 0;
    ll sincejoin = 0;
    while(1){
        ll lo = LLONG_MAX;
        ll best = -1;
        int bestind = -1;
        for(int i = 0; i < n; i++){
            if(b[i] > best){
                best = b[i];
                bestind = i;
            }
            lo = min(lo, b[i]);
        }
        if(lo >= 0){
            cout << ans << endl;
            return 0;
        }
        if(best <= 0){
            cout << "never" << endl;
            return 0;
        }
        sincejoin++;
        if(b[a[bestind]]) sincejoin = 0;
        if(sincejoin > 2*n+3){
            cout << "never" << endl;
            return 0;
        }
        b[a[bestind]] += b[bestind];
        b[bestind] = 0;
        ans++;
    }
}
