#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
constexpr int inf = 0x3f3f3f3f;
#define sz(x) ((int)(x).size())

int N, M;
vi b;

// O(n log n) genom binärsökning och matte
// bara O(log n) efter sorteringen
int solve_binsearch_math(){
    sort(b.begin(), b.end());
    int ans = 0;
    int lo = 0, hi = N;
    while(1){
        int i = (lo+hi-1)/2;
        int p = N-i;
        int t;
        if(p > M) t = inf;
        else{
            t = 2*p;
            if(p > (M+1)/2){
                t += 2*(p-(M+1)/2);
                if(M%2 == 0) t--;
            }
        }
        if(t <= b[i]) ans = max(ans, p);
        if(lo+1 == hi) break;
        if(t <= b[i])
            hi = i+1;
        else
            lo = i+1;
    }
    return ans;
}

int main(){
    cin >> N >> M;
    b = vi(N);
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    int ans = solve_binsearch_math();
    cout << ans << endl;
}
