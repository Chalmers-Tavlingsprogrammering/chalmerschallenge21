#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
constexpr int inf = 0x3f3f3f3f;
#define sz(x) ((int)(x).size())

int N, M;
vi b;

// O(n log n) genom att använda matte
// bara O(n) efter sorteringen
int solve_math(){
    sort(b.begin(), b.end());
    int ans = 0;
    for(int i = 0; i < N; i++){
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
    }
    return ans;
}

int main(){
    cin >> N >> M;
    b = vi(N);
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    int ans = solve_math();
    cout << ans << endl;
}
