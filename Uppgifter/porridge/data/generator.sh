#!/bin/bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

# For unlimited stack:
# ulimit -s unlimited

# Choose your solution
use_solution porridge_solved.py

# Compile generators
compile gen_random.py

# Generate answers to sample cases (optional)
sample 01
sample 02
sample 03
sample 04

# Note: tc automatically adds a deterministic, pseudo-random seed argument to your generator
tc t01 gen_random max_N=100 max_M=100 max_I=100 prob_same=1
tc t02 gen_random max_N=1000 max_M=1000 max_I=1000
tc t03 gen_random max_N=10000 max_M=10000 max_I=10000
tc t04 gen_random max_N=100000 max_M=100000 max_I=100000

tc t10 gen_random
tc t11 gen_random
tc t12 gen_random
tc t13 gen_random
tc t14 gen_random
tc t15 gen_random
tc t16 gen_random
tc t17 gen_random

#tc_manual ../manual-tests/1.in
