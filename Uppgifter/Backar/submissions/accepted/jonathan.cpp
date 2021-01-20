#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
#define sz(x) ((int)(x).size())
constexpr int inf = 0x3f3f3f3f;

int main(){
    int n_spots, n_connections;
    cin >> n_spots >> n_connections;

    int start, end;
    cin >> start >> end;

    vl heights(n_spots);
    for(int i = 0; i < n_spots; i++) cin >> heights[i];

    vvi connections(n_spots);
    for (int i = 0; i < n_spots; i++) {
        connections[i] = vector<int>(0);
    }

    for(int i = 0; i < n_spots; i++){
        int a, b;
        cin >> a >> b;
        connections[a - 1].push_back(b - 1);
        connections[b - 1].push_back(a - 1);
    }
    //etc etc
    cout << 0 << endl;
}
