#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 1234567890123456789;

int main(){
    ll n;
    cin >> n;
    vl a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    ll pos = 0;
    for(int i = 0; i < n; i++){
        while(1){
            if(pos == a[i]) break;
            ll closest = linf;
            for(int e = 0; e < 30; e++){
                if(abs(pos+(1ll << e) - a[i]) < abs(closest-a[i])){
                    closest = pos+(1ll << e);
                }
                if(abs(pos-(1ll << e) - a[i]) < abs(closest-a[i])){
                    closest = pos-(1ll << e);
                }
            }
            pos = closest;
            ans++;
        }
    }
    
    cout << ans << endl;
}
