#!/bin/bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

# For unlimited stack:
# ulimit -s unlimited

# Choose your solution
use_solution chactl_solved.py

# Compile generators
compile chactl_gen_rand.py

# Generate answers to sample cases (optional)
sample 01
sample 02
sample 03

# Note: tc automatically adds a deterministic, pseudo-random seed argument to your generator
tc t01 chactl_gen_rand max_N=1e2 max_page=2048
tc t02 chactl_gen_rand max_N=1e3 max_page=2048
tc t03 chactl_gen_rand max_N=1e4 max_page=2048
tc t04 chactl_gen_rand max_N=1e5 max_page=2048

tc t05 chactl_gen_rand max_N=1e3 max_page=2^26
tc t06 chactl_gen_rand max_N=1e4 max_page=2^26

tc t07 chactl_gen_rand max_N=1e5 max_page=2^26
tc t08 chactl_gen_rand max_N=1e5 max_page=2^26
tc t09 chactl_gen_rand max_N=1e5 max_page=2^26
tc t10 chactl_gen_rand max_N=1e5 max_page=2^26
tc t11 chactl_gen_rand max_N=1e5 max_page=2^26
tc t12 chactl_gen_rand max_N=1e5 max_page=2^26
#tc_manual ../manual-tests/1.in
