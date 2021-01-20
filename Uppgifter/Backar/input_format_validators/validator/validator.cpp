#include "validator.h"

typedef long long ll;

void run() {
	int max_n = 100000;
	int max_m = 100000;

	int n_spots = Int(2, max_n);
	Space();
	int n_conns = Int(1, max_m);
	Endl();

	int start = Int(1, max_n);
	Space();
	int end = Int(1, max_n);
	Endl();

	for(int i = 1; i <= n_spots; i++){
		Int(-1e9, 1e9);
		if(i != n_spots) Space();
	}
	Endl();

	for(int i = 1; i <= n_conns; i++){
		Int(1, max_n);
		Space();
		Int(1, max_n);
		Endl();
	}
	Eof();
}
