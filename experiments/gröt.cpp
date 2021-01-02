#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
constexpr int inf = 0x3f3f3f3f;
#define sz(x) ((int)(x).size())

int N; //antal studenter
int M; //tid tills gröt blir kall
vi a; //otålighet

// exponentiell komplexitet
int solve_bruteforce(int t=0, int kalla=0, vi varma=vi{}){
    int ans = -1;

    //servera
    int s = 0;
    for(int i = 0; i < N; i++) s += t <= a[i];
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

// O(n^2)
int solve_n2(){
    vi b = a;
    sort(b.begin(), b.end());
    int ans = 0;
    for(int i = 0; i < N; i++){
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
    }
    return ans;
}

// O(n log n) genom binärsökning
int solve_binsearch(){
    vi b = a;
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

// O(n log n) genom att använda matte
// bara O(n) efter sorteringen
int solve_math(){
    vi b = a;
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

// O(n log n) genom binärsökning och matte
// bara O(log n) efter sorteringen
int solve_binsearch_math(){
    vi b = a;
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

int gettime(int p, int m){
    int t = 0;
    queue<int> k;
    for(int j = 0; j < p; j++){
        t += 2;
        k.push(t+m);
    }
    int cnt = 0;
    while(sz(k) && k.front() <= t){
        t += 1;
        k.pop();
        k.push(t+m);
        cnt++;
        if(cnt > N+10){
            t = inf;
            break;
        }
    }
    return t;
}

int gettime2(int p, int m){
    int t;
    if(p > m) t = inf;
    else{
        t = 2*p;
        if(p > (m+1)/2){
            t += 2*(p-(m+1)/2);
            if(m%2 == 0) t--;
        }
    }
    return t;
}

void gen_random(int max_n, int max_m, int max_o){
    N = rand()%max_n + 1;
    M = rand()%max_m + 1;
    a = vi(N);
    for(int i = 0; i < N; i++){
        a[i] = rand()%(max_o+1);
    }
}

int main(){
    srand(time(0));
/*
    int m = 10;
    for(int p = 0; p < 15; p++){
        cout << p << " " << gettime(p, m) << " " << gettime2(p, m) << endl;
    }
    return 0;*/

    int t = 100000;
    for(int i = 0; i < t; i++){
        gen_random(100, 20, 50);

        int ans1 = solve_n2();
        int ans2 = solve_binsearch_math();
        
        cout << ans1 << " " << ans2 << endl;
        assert(ans1 == ans2);
        cout << "--- OK ---" << endl;
    }
}
