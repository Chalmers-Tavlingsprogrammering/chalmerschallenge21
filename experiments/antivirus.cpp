#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
constexpr int inf = 0x3f3f3f3f;
#define sz(x) ((int)(x).size())

int N;
vi A;
vl B;

int solve(){
    int n = N;
    vi a = A;
    vl b = B;
    vi c(n, 1);

    ll ans = 0;
    set<pair<ll, int>> pq;
    for(int i = 0; i < n; i++) pq.emplace(-b[i], i);
    ll sincejoin = 0;
    while(1){
        int from = (*pq.begin()).second;
        ll best = b[from];
        if(-(*pq.rbegin()).first >= 0){
            return ans;
        }
        if(best <= 0){
            return -42;
        }

        int dest = a[from];
        int dist = c[from];
        int prevdest = from;
        
        while(prevdest != 0 && dest != 0 && b[dest] == 0){
            prevdest = dest;
            dist += c[dest];
            dest = a[dest];
        }
        sincejoin++;
        if(b[dest]) sincejoin = 0;
        if(sincejoin > 2*n+3){
            return -42;
        }

        pq.erase(pq.begin());
        pq.emplace(0, from);
        pq.erase({-b[dest], dest});
        b[dest] += b[from];
        pq.emplace(-b[dest], dest);
        b[from] = 0;

        ans+=dist;

        while(dist){
            int nxt = a[from];
            int nd = c[from];
            a[from] = dest;
            c[from] = dist;
            from = nxt;
            dist -= nd;
        }
    }
}

ll n3(){
    ll n = N;
    vl a(n);
    for(ll i = 0; i < n; i++) a[i] = A[i];
    vl b = B;
    ll ans = 0;
    ll sincejoin = 0;
    while(1){
        ll lo = LLONG_MAX;
        ll best = -1;
        ll bestind = -1;
        for(ll i = 0; i < n; i++){
            if(b[i] > best){
                best = b[i];
                bestind = i;
            }
            lo = min(lo, b[i]);
        }
        if(lo >= 0){
            return ans;
        }
        if(best <= 0){
            return -42;
        }
        sincejoin++;
        if(b[a[bestind]]) sincejoin = 0;
        if(sincejoin > 5*n+100){
            return -42;
        }
        b[a[bestind]] += b[bestind];
        b[bestind] = 0;
        ans++;
    }
}

int randint(int lo, int hi){
    return ((ll(rand()) << 20) + rand())%((ll)hi-lo+1)+lo;
}

void gen(int n){
    N = n;
    A = vi(N);
    B = vl(N);
    for(int i = 0; i < n; i++){
        if(i == 0) A[i] = rand()%(n-1)+1;
        else A[i] = rand()%i;
    }
    for(int i = 0; i < n; i++){
        B[i] = randint(-1,3);
    }
}

int main(){
    for(int i = 0; i < 1000000; i++){
        gen(30);
        int ans1 = solve();
        ll ans2 = n3();
        if(ans1 == -42 && ans2 == -42) continue;
        cout << ans1 << " " << ans2 << endl;
        if(i%1000 == 0) cout << i << endl;
        assert(ans1 == ans2);
    }
    cout << "OK" << endl;
}
