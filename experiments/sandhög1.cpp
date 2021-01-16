#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
constexpr int inf = 0x3f3f3f3f;

/*
    Anton Sandhög, versionen från trellon (cirkel)
*/

int n;
vl a;

// O(n^3) worst-case
ll solve_brute(){
    vl b = a;
    ll ans = 0;
    while(1){
        int p = max_element(all(b))-b.begin();
        if(b[p] == 0) break;
        b[(p+1)%n] += b[p];
        b[p] = 0;
        ans++;
    }
    return ans;
}

// O(n log n) med set
ll solve_fast(){
    vl b = a;
    vi next(n);
    vi prev(n);
    for(int i = 0; i < 2*n; i++){
        if(b[(i-1+n)%n]) prev[i%n] = (i-1+n)%n;
        else prev[i%n] = prev[(i-1+n)%n];
    }
    for(int i = 2*n-1; i >= 0; i--){
        if(b[(i+1)%n]) next[i%n] = (i+1)%n;
        else next[i%n] = next[(i+1)%n];
    }
    set<pair<ll, int>> s;
    for(int i = 0; i < n; i++) s.emplace(-b[i], i);
    ll ans = 0;
    while(1){
        if((*s.begin()).first == 0) break;
        int p = (*s.begin()).second;
        int np = next[p];
        int pp = prev[p];
        pair<ll, int> rm = {-b[np], np};
        pair<ll, int> rm2 = {-b[p], p};
        prev[np] = pp;
        next[pp] = np;
        b[np] += b[p];
        b[p] = 0;
        ans += (np-p+n)%n;
        s.erase(rm2);
        s.erase(rm);
        s.emplace(-b[np], np);
    }
    return ans;
}

void gen_rand(int max_n){
    n = rand()%max_n+1;
    a = vl(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        a[i] = rand()%10001-5000; //ska egentligen vara 10^9 <= a[i] <= 10^9, men det borde inte påverka lösningarnas korrekthet (förutom vid overflow).
        sum += a[i];
    }
    while(sum > 0){
        a[rand()%n]--;
        sum--;
    }
    while(sum < 0){
        a[rand()%n]++;
        sum++;
    }
}

int main(){
    for(int i = 0; i < 10; i++){
        gen_rand(1000);
        int ans1 = solve_brute();
        int ans2 = solve_fast();
        cout << ans1 << " " << ans2 << endl;
        assert(ans1 == ans2);
    }
}
