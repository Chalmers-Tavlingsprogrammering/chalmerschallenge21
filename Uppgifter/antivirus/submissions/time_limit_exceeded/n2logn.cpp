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
    set<pair<ll, int>> pq;
    for(int i = 0; i < n; i++) pq.emplace(-b[i], i);
    while(1){
        int bestind = (*pq.begin()).second;
        ll best = b[bestind];
        if(-(*pq.rbegin()).first >= 0){
            cout << ans << endl;
            return 0;
        }
        if(best <= 0){
            cout << "never" << endl;
            return 0;
        }
        pq.erase(pq.begin());
        pq.emplace(0, bestind);
        pq.erase({-b[a[bestind]], a[bestind]});
        sincejoin++;
        if(b[a[bestind]]) sincejoin = 0;
        if(sincejoin > 2*n+3){
            cout << "never" << endl;
            return 0;
        }
        b[a[bestind]] += b[bestind];
        pq.emplace(-b[a[bestind]], a[bestind]);
        b[bestind] = 0;
        ans++;
    }
}
