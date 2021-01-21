#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
constexpr int inf = 0x3f3f3f3f;
#define sz(x) ((int)(x).size())

int N, M;
vi b;

// O(n log n) genom binärsökning
int solve_binsearch(){
    sort(b.begin(), b.end());
    int ans = 0;
    int lo = 0, hi = N;
    while(1){
        int i = (lo+hi-1)/2;
        int p = N-i;

        //strategi: laga alla, värm sedan alla som blivit kalla tills inga är kalla
        int t = 0;
        queue<int> k;
        for(int j = 0; j < p; j++){
            t += 2;
            k.push(t+M);
        }
        int cnt = 0;
        while(sz(k) && k.front() <= t){
            t += 1;
            k.pop();
            k.push(t+M);
            cnt++;
            if(cnt > N+10){
                t = inf;
                break;
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
    int ans = solve_binsearch();
    cout << ans << endl;
}
