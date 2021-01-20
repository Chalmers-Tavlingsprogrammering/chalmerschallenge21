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
tc t01 kcud_gen_rand max_N=1245 max_M=222
tc t02 kcud_gen_rand max_N=74018 max_M=2
tc t03 kcud_gen_rand max_N=99999 max_M=99998
tc t04 kcud_gen_rand max_N=42 max_M=27
tc t05 kcud_gen_rand max_N=1 max_M=2
tc t06 kcud_gen_rand max_N=666 max_M=3245
tc t07 kcud_gen_rand max_N=10001 max_M=70001
tc t08 kcud_gen_rand max_N=345 max_M=342
tc t09 kcud_gen_rand max_N=2 max_M=67892
tc t10 kcud_gen_rand max_N=25252 max_M=52525
tc t11 kcud_gen_rand max_N=31205 max_M=2004
tc t12 kcud_gen_rand max_N=433 max_M=353
#tc_manual ../manual-tests/1.in
