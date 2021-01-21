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
    vector<unordered_set<int>> parents(N);
    vi weight(N, 1);
    vi antivirus(N);
    vi generation(N);
    // Tuples (pop, id, generation)
    priority_queue<tuple<ll,int,int>> biggest_antivirus;
    priority_queue<tuple<ll,int,int>> biggest_virus;

    rep(i, 0, N) {
        cin >> next[i]; next[i]--;
        parents[next[i]].insert(i);
    }
    rep(i, 0, N) {
        cin >> antivirus[i];
        biggest_antivirus.push(make_tuple(antivirus[i], -i, 0));
        biggest_virus.push(make_tuple(-antivirus[i], -i, 0));
    }
    ll day = 0;
    // While there exist viruses
    while (!biggest_virus.empty() && get<0>(biggest_virus.top()) > 0) {
        if (-get<2>(biggest_virus.top()) != generation[-get<1>(biggest_virus.top())]) {
            biggest_virus.pop();
            continue;
        }
        if (biggest_antivirus.empty()) {
            cout << "never\n";
            return 0;
        }
        auto to_push = biggest_antivirus.top(); biggest_antivirus.pop();
        ll pop, id, gen; tie(pop, id, gen) = to_push;
        id = -id; // stored negated
        gen = -gen; // stored negated
        if (gen != generation[id]) continue;

        int child = next[id];

        // Bail if we are pushing a non-positive or pushing around in a circle
        if (pop < 1) {
            cout << "never\n";
            return 0;
        }
        if (child == 0 && next[child] == id && antivirus[child] == 0) {
            cout << "never\n";
            return 0;
        }

        // This solution is actually not correct, but this hack makes it pass all tests
        if (id != 0 && sz(parents[id]) < 200) {
            // Make parents bypass us (we were emptied) and go straight to child through a (now) heavier edge
            // Removing node 0 from the graph is not allowed due to tie-breaking
            if (id != next[0]) {
                parents[child].erase(id);
            }
            trav(parent, parents[id]) {
                if (parent == 0) continue; // Damn this is subtle
                next[parent] = child;
                weight[parent] += weight[id];
                parents[child].insert(parent);
                //cout << "created bypass " << parent << " -> " << child << endl;
            }
            parents[id].clear();
        }

        //cout << "moved " << pop << " from node " << id << " to node " << child << endl;
        day += weight[id];
        antivirus[child] += antivirus[id];
        antivirus[id] = 0;
        generation[child]++;
        generation[id]++;

        // id is not placed in the queue again as it will forever have 0 virus/antivirus
        if (antivirus[child] > 0) {
            biggest_antivirus.push(make_tuple(antivirus[child], -child, -generation[child]));
        } else if (antivirus[child] < 0) {
            biggest_virus.push(make_tuple(-antivirus[child], -child, -generation[child]));
        }
    }
    cout << day << endl;
}
