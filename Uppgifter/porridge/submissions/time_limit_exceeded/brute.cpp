#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
constexpr int inf = 0x3f3f3f3f;
#define sz(x) ((int)(x).size())

int N, M;
vi b;

// exponentiell komplexitet
int solve_bruteforce(int t=0, int kalla=0, vi varma=vi{}){
    int ans = -1;

    //servera
    int s = 0;
    for(int i = 0; i < N; i++) s += t <= b[i];
    ans = max(ans, min(s, sz(varma)));

    if(s == 0) return 0;

    //laga gröt (2 min)
    vi ny_varma = varma;
    int ny_kalla = kalla;
    for(int i = 0; i < sz(ny_varma); i++){
        ny_varma[i] -= 2;
    }
    while(sz(ny_varma) && ny_varma[0] <= 0){
        ny_varma.erase(ny_varma.begin());
        ny_kalla++;
    }
    ny_varma.push_back(M);
    ans = max(ans, solve_bruteforce(t+2, ny_kalla, ny_varma));

    //värma gröt (1 min)
    if(kalla){
        ny_varma = varma;
        ny_kalla = kalla;
        for(int i = 0; i < sz(ny_varma); i++){
            ny_varma[i]--;
        }
        while(sz(ny_varma) && ny_varma[0] <= 0){
            ny_varma.erase(ny_varma.begin());
            ny_kalla++;
        }
        ny_kalla--;
        ny_varma.push_back(M);
        ans = max(ans, solve_bruteforce(t+1, ny_kalla, ny_varma));
    }
    return ans;
}

int main(){
    cin >> N >> M;
    b = vi(N);
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    int ans = solve_bruteforce();
    cout << ans << endl;
}
