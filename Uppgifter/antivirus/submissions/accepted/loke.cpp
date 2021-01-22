#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int N; cin >> N;
    vi next(N);
    vi weight(N, 1);
    vi antivirus(N);
    // (antivirus amount, id)
    priority_queue<pair<ll,int>> biggest_antivirus;
    priority_queue<pair<ll,int>> biggest_virus;
    ll day = 0;

    rep(i, 0, N) {
        cin >> next[i]; next[i]--;
    }
    rep(i, 0, N) {
        cin >> antivirus[i];
        if (antivirus[i] > 0) {
            biggest_antivirus.push(make_pair(antivirus[i], -i));
        } else if (antivirus[i] < 0) {
            biggest_virus.push(make_pair(-antivirus[i], -i));
        }
    }
    // While there exist viruses
    while (!biggest_virus.empty() && biggest_virus.top().first > 0) {
        if (-biggest_virus.top().first != antivirus[-biggest_virus.top().second]) {
            biggest_virus.pop();
            continue; // Repeat if we got invalidated virus pile
        }
        if (biggest_antivirus.empty()) {
            cout << "never\n";
            return 0;
        }

        ll pop = biggest_antivirus.top().first;
        int id = -biggest_antivirus.top().second; // stored negated
        biggest_antivirus.pop();
        if (antivirus[id] != pop) {
            continue; // Repeat if we got invalidated antivirus pile
        }

        int child = next[id];

        // Bail if we are pushing a non-positive or pushing around in a circle
        if (pop < 1 || (antivirus[child] == 0 && child == 0 && next[child] == id)) {
            cout << "never\n";
            return 0;
        }

        // Contract edge between child and next[child] if that's valid
        if (antivirus[child] == 0 && child != 0 && child != next[0]) {
            next[id] = next[child];
            weight[id] += weight[child];
            child = next[id]; // requires this new value now
        }

        //cout << "moved " << pop << " from node " << id << " to node " << child << endl;
        day += weight[id];
        antivirus[child] += antivirus[id];
        antivirus[id] = 0;

        // id is not placed in a queue as it has value 0
        if (antivirus[child] > 0) {
            biggest_antivirus.push(make_pair(antivirus[child], -child));
        } else if (antivirus[child] < 0) {
            biggest_virus.push(make_pair(-antivirus[child], -child));
        }
    }
    cout << day << endl;
}
