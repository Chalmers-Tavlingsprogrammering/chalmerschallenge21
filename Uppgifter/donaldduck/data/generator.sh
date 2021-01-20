#!/bin/bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

# For unlimited stack:
# ulimit -s unlimited

# Choose your solution
use_solution kcud_solved.py

# Compile generators
compile kcud_gen_rand.py

# Generate answers to sample cases (optional)
sample 01
sample 02
sample 03

# Note: tc automatically adds a deterministic, pseudo-random seed argument to your generator
tc t01 kcud_gen_rand max_N=10 max_M=10
tc t02 kcud_gen_rand max_N=100 max_M=100
tc t03 kcud_gen_rand max_N=1000 max_M=1000
tc t04 kcud_gen_rand max_N=10000 max_M=10000
tc t05 kcud_gen_rand max_N=100000 max_M=100000

tc t06 kcud_gen_rand
tc t07 kcud_gen_rand
tc t08 kcud_gen_rand
tc t09 kcud_gen_rand
tc t10 kcud_gen_rand
tc t11 kcud_gen_rand
tc t12 kcud_gen_rand
#tc_manual ../manual-tests/1.in
