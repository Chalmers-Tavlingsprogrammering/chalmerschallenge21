#include "validator.h"

typedef long long ll;

void run() {
	int max_n = 100000;

	int n = Int(2, max_n);
	Endl();

	for(int i = 0; i < n; i++){
		Int(-1e9, 1e9);
		if(i != n-1) Space();
	}
	Endl();

	for(int i = 1; i <= n; i++){
		if(i == 1) Int(2, n);
		else Int(1, n-1);
		if(i != n) Space();
	}
	Endl();
	Eof();
}
