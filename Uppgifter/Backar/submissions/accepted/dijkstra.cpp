#pragma GCC optimize ("O3")
#include <set>
#include <functional>
#include <vector>
#include <utility>
#include <tuple>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
#define sz(x) ((int)(x).size())
constexpr int inf = 0x3f3f3f3f;


int main() {
	int n_spots, n_conns;
	cin >> n_spots >> n_conns;

    int start, end;
	cin >> start >> end;
	start--; end--;

    vector<int> heights = std::vector<int>(n_spots);
	for(int i = 0; i < n_spots; i++){
    	cin >> heights[i];
	}

	vector<set<int>> connections(n_spots);
	for (int i = 0; i < n_spots; i++) {
		connections[i] = set<int>();
	}

	for(int i = 1; i <= n_conns; i++){
    	int from, to;
    	cin >> from >> to;
		connections[from - 1].insert(to - 1);
		connections[to - 1].insert(from - 1);
	}

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    set<int> visited = set<int>();
    heap.push(pair<int, int>(0, start));
    while (!heap.empty()) {
        int dist, idx;
        tie(dist, idx) = heap.top();
        heap.pop();

        if (visited.find(idx) != visited.end()) {
            continue;
        }

        visited.insert(idx);

        if (idx == end) {
            std::cout << dist << std::endl;
            return 0;
        }

        int height_here = heights[idx];
        for (int conn : connections[idx]) {
            int height_there = heights[conn];
            int cost = height_here < height_there ? height_there - height_here : 0;
            heap.push(pair<int, int>(dist + cost, conn));
        }
    }
}
