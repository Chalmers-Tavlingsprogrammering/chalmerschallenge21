#include "validator.h"
#include <set>
#include <vector>
#include <string>
#include <stdlib.h>

typedef long long ll;

bool dfs_find_way(vector<set<int>> &connections, set<int> &visited, int at, int wanted) {
    if (at == wanted) { return true; }
    if (visited.find(at) != visited.end()) { return false; } // Already visited

    visited.insert(at);

    for (int conn : connections[at]) {
        if (dfs_find_way(connections, visited, conn, wanted)) {
            return true;
        }
    }
    return false;
}

void run() {
	int max_n = 100000;
	int max_m = 100000;

	int n_spots = Int(2, max_n);
	Space();
	int n_conns = Int(1, max_m);
	Endl();

	int start = (int) Int(1, max_n) - 1;
	Space();
	int end = (int) Int(1, max_n) - 1;
	Endl();

	for(int i = 1; i <= n_spots; i++){
		Int(-1e5, 1e5);
		if(i != n_spots) Space();
	}
	Endl();

	vector<set<int>> connections(n_spots);
	for (int i = 0; i < n_spots; i++) {
		connections[i] = set<int>();
	}

	for(int i = 1; i <= n_conns; i++){
		int from = (int) Int(1, max_n) - 1;
		Space();
		int to = (int) Int(1, max_n) - 1;
		Endl();

		if (from == to) {
			ostringstream x;
			x << "Self connection at ";
			x << to + 1;
			x << "!";
			die(x.str());
		}

		if (connections[from].find(to) == connections[from].end()) {
			connections[from].insert(to);
		} else {
			ostringstream x;
			x << "Connection ";
			x << from + 1;
			x << " to ";
			x << to + 1;
			x << " specified twice!";
			die(x.str());
		}

		if (connections[to].find(from) == connections[to].end()) {
			connections[to].insert(from);
		} else {
			ostringstream x;
			x << "Connection ";
			x << to + 1;
			x << " to ";
			x << from + 1;
			x << " specified twice!";
			die(x.str());
		}
	}
	Eof();

    set<int> visited;
	if (!dfs_find_way(connections, visited, start, end)) {
        die("No path found!");
	}
}
