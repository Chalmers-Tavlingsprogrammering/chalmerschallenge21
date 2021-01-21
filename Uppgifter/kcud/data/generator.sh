#!/bin/bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

# For unlimited stack:
# ulimit -s unlimited

# Choose your solution
use_solution kcud_solved.py

# Compile generators
compile gen_exact.py

# Generate answers to sample cases (optional)
sample 01
sample 02
sample 03

# Note: tc automatically adds a deterministic, pseudo-random seed argument to your generator
tc t01 gen_exact   N=1245     M=222
tc t02 gen_exact   N=74018    M=2
tc t03 gen_exact   N=99999    M=99998
tc t04 gen_exact   N=42       M=27
tc t05 gen_exact   N=1        M=2
tc t06 gen_exact   N=666      M=3245
tc t07 gen_exact   N=10001    M=70001
tc t08 gen_exact   N=345      M=342
tc t09 gen_exact   N=2        M=67892
tc t10 gen_exact   N=25252    M=52525
tc t11 gen_exact   N=31205    M=2004
tc t12 gen_exact   N=433      M=353
tc t13 gen_exact   N=999989   M=999998
tc t14 gen_exact   N=2        M=4
tc t15 gen_exact   N=4        M=2
tc t16 gen_exact   N=5        M=4
tc t17 gen_exact   N=4        M=5
tc t18 gen_exact   N=13585    M=12483
tc t19 gen_exact   N=13595    M=12483
tc t20 gen_exact   N=12483    M=13585
tc t21 gen_exact   N=95       M=12
#tc_manual ../manual-tests/1.in
