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
tc t01 kcud_gen_rand    N=1245     M=222
tc t02 kcud_gen_rand    N=74018    M=2
tc t03 kcud_gen_rand    N=99999    M=99998
tc t04 kcud_gen_rand    N=42       M=27
tc t05 kcud_gen_rand    N=1        M=2
tc t06 kcud_gen_rand    N=666      M=3245
tc t07 kcud_gen_rand    N=10001    M=70001
tc t08 kcud_gen_rand    N=345      M=342
tc t09 kcud_gen_rand    N=2        M=67892
tc t10 kcud_gen_rand    N=25252    M=52525
tc t11 kcud_gen_rand    N=31205    M=2004
tc t12 kcud_gen_rand    N=433      M=353
tc t13 kcud_gen_rand    N=999989   M=999998
tc t14 kcud_gen_rand    N=2        M=4
tc t15 kcud_gen_rand    N=4        M=2
tc t16 kcud_gen_rand    N=5        M=4
tc t17 kcud_gen_rand    N=4        M=5
tc t18 kcud_gen_rand    N=13585    M=12483
tc t19 kcud_gen_rand    N=13595    M=12483
tc t20 kcud_gen_rand    N=12483    M=13585
#tc_manual ../manual-tests/1.in
