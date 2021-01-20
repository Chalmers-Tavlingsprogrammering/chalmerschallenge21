#!/bin/bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

# For unlimited stack:
# ulimit -s unlimited

# Choose your solution
use_solution chactl_recursive.py

# Compile generators
compile chactl_gen_rand.py

# Generate answers to sample cases (optional)
sample 01
sample 02
sample 03

# Note: tc automatically adds a deterministic, pseudo-random seed argument to your generator
tc t01 chactl_gen_rand max_N=100 max_page=2048
tc t02 chactl_gen_rand max_N=1000 max_page=2048
tc t03 chactl_gen_rand max_N=10000 max_page=2048
tc t04 chactl_gen_rand max_N=100000 max_page=2048

# 2**26 = 67108864, I have no idea why I am not allowed to just write the expression
tc t05 chactl_gen_rand max_N=1000 max_page=67108864
tc t06 chactl_gen_rand max_N=10000 max_page=67108864

tc t07 chactl_gen_rand max_N=100000 max_page=67108864
tc t08 chactl_gen_rand max_N=100000 max_page=67108864
tc t09 chactl_gen_rand max_N=100000 max_page=67108864
tc t10 chactl_gen_rand max_N=100000 max_page=67108864
tc t11 chactl_gen_rand max_N=100000 max_page=67108864
tc t12 chactl_gen_rand max_N=100000 max_page=67108864
#tc_manual ../manual-tests/1.in
