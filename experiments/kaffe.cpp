#include <bits/stdc++.h>
using namespace std;

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

void gen_random(int n, int l, int d, int max_v, int max_m, int max_k){
    N = n, L = l, D = d;
    a.clear();
    for(int i = 0; i < n; i++){
        a.emplace_back(rand()%max_v, rand()%max_m, rand()%max_k);
    }
}

int main(){
    int t = 10;
    for(int i = 0; i < t; i++){
        gen_random(22, 100, 40, 22, 8, 50);
        int ans = solve_bruteforce();
        cout << ans << endl;
    }
}