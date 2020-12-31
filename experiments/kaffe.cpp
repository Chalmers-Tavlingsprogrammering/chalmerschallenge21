//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
constexpr int inf = 0x3f3f3f3f;

struct kopp{
    kopp(int V, int M, int K) : V(V), M(M), K(K) { }

    int V; //Mängd kaffe
    int M; //Mängden mjölk som krävs
    int K; //Mängd koffein
};

int N; //Antal kaffekoppar
int L; //Hur mycket han kan dricka
int D; //Tillgänglig mängd mjölk

vector<kopp> a;

// O(2^N*N)
int solve_bruteforce(){
    int best = -1;
    for(int i = 0; i < (1<<N); i++){
        int dric = 0;
        int milk = 0;
        int koff = 0;
        for(int j = 0; j < N; j++){
            if(i>>j&1){
                dric += a[j].V + a[j].M;
                milk += a[j].M;
                koff += a[j].K;
            }
        }
        if(milk <= D && dric <= L) best = max(best, koff);
    }
    return best;
}

// O(N * D * L)
int solve_dp_1(){
    vector<vvi> dp(N+1, vvi(D+1, vi(L+1))); //kopp, mjölk kvar, drickmängd kvar ==> hur mycket koffein man kan få
    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j <= D; j++){
            for(int k = 0; k <= L; k++){
                dp[i][j][k] = dp[i+1][j][k];
                if(j-a[i].M >= 0 && k-(a[i].V+a[i].M) >= 0){
                    dp[i][j][k] = max(dp[i][j][k], dp[i+1][j-a[i].M][k-(a[i].V+a[i].M)] + a[i].K);
                }
            }
        }
    }
    return dp[0][D][L];
}

// O(N * D * sum(koffein))
int solve_dp_2(){
    int sum = 0;
    for(int i = 0; i < N; i++) sum += a[i].K;
    vector<vvi> dp(N+1, vvi(D+1, vi(sum+1))); //kopp, mjölk kvar, ytterliggare koffein som behövs ==> hur mycket som behöver drickas

    for(int j = 0; j <= D; j++) for(int k = 0; k <= sum; k++) dp[N][j][k] = inf;
    for(int j = 0; j <= D; j++) dp[N][j][0] = 0;
    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j <= D; j++){
            for(int k = 0; k <= sum; k++){
                dp[i][j][k] = dp[i+1][j][k];
                if(j-a[i].M >= 0){
                    dp[i][j][k] = min(dp[i][j][k], dp[i+1][j-a[i].M][max(0, k-a[i].K)] + a[i].V+a[i].M);
                }
            }
        }
    }

    int ans = sum;
    while(dp[0][D][ans] > L) ans--;
    return ans;
}

// O(N * L * sum(koffein))
// aldrig snabbare än solve_dp_2 om man kör D = min(D, L) (vilket inte påverkar lösningen).
int solve_dp_3(){
    int sum = 0;
    for(int i = 0; i < N; i++) sum += a[i].K;
    vector<vvi> dp(N+1, vvi(L+1, vi(sum+1))); //kopp, drickmängd kvar, ytterliggare koffein som behövs ==> hur mycket mjölk som behövs

    for(int j = 0; j <= L; j++) for(int k = 0; k <= sum; k++) dp[N][j][k] = inf;
    for(int j = 0; j <= L; j++) dp[N][j][0] = 0;
    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j <= L; j++){
            for(int k = 0; k <= sum; k++){
                dp[i][j][k] = dp[i+1][j][k];
                if(j - (a[i].V + a[i].M) >= 0){
                    dp[i][j][k] = min(dp[i][j][k], dp[i+1][j - (a[i].V + a[i].M)][max(0, k-a[i].K)] + a[i].M);
                }
            }
        }
    }

    int ans = sum;
    while(dp[0][L][ans] > D) ans--;
    return ans;
}

void gen_random(int max_n, int max_l, int max_d, int max_v, int max_m, int max_k){
    N = max_n ? rand()%max_n : 0;
    L = max_l ? rand()%max_l : 0;
    D = max_d ? rand()%max_d : 0;
    a.clear();
    for(int i = 0; i < N; i++){
        a.emplace_back(max_v ? rand()%max_v : 0,
                       max_m ? rand()%max_m : 0,
                       max_k ? rand()%max_k : 0);
    }
}

int main(){
    srand(time(0));

    int t = 1000000;
    for(int i = 0; i < t; i++){
        gen_random(22, 100, 40, 22, 8, 50);

        int ans1 = solve_dp_2();
        int ans2 = solve_dp_3();
        cout << ans1 << " " << ans2 << endl;
        assert(ans1 == ans2);
        cout << "--- OK ---" << endl;
    }
}