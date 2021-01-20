#!/bin/bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

# For unlimited stack:
# ulimit -s unlimited

# Choose your solution
use_solution gustav.cpp

# Compile generators
compile gen_random.py
compile gen_notnever.py
compile gen_maxans.py
compile gen_compressiontest.py

# Generate answers to sample cases (optional)
sample 01
sample 02

# Note: tc automatically adds a deterministic, pseudo-random seed argument to your generator
tc t01 gen_random   n=2
tc t03 gen_random   n=3
tc t04 gen_random   n=4     min_b=-3    max_b=3
tc t05 gen_random   n=6     min_b=0     max_b=3
tc t06 gen_random   n=6     min_b=1     max_b=3
tc t07 gen_random   n=10    min_b=-3    max_b=0
tc t08 gen_random   n=10    min_b=-3    max_b=-1
tc t09 gen_random   n=100
tc t10 gen_random   n=1000
tc t11 gen_random   n=1000  min_b=-1000000
tc t12 gen_notnever n=2
tc t13 gen_notnever n=6
tc t14 gen_notnever n=100
tc t15 gen_notnever n=999
tc t16 gen_notnever n=1000 min_b=-5   max_b=5
tc t17 gen_notnever n=1000 min_b=-1   max_b=1
tc t18 gen_notnever n=12345
tc t19 gen_maxans   n=1000
tc t20 gen_maxans   n=10000
tc t21 gen_maxans   n=200000
tc t22 gen_compressiontest n=200000
#tc t19 gen_notnever n=200000
#notnever circlesize
tc_manual ../manual-tests/zerocircle1.in
tc_manual ../manual-tests/zerocircle2.in

