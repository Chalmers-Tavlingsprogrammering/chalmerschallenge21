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
compile gen_star.py

# Generate answers to sample cases (optional)
sample 01
sample 02
sample 03

# Note: tc automatically adds a deterministic, pseudo-random seed argument to your generator
tc t01 gen_random   n=2
tc t02 gen_random   n=3
tc t03 gen_random   n=4     min_b=-3    max_b=3
tc t04 gen_random   n=6     min_b=0     max_b=3
tc t05 gen_random   n=6     min_b=1     max_b=3
tc t06 gen_random   n=10    min_b=-3    max_b=0
tc t07 gen_random   n=10    min_b=-3    max_b=-1
tc t08 gen_random   n=100
tc t09 gen_random   n=1000
tc t10 gen_random   n=1000  min_b=-1000000
tc t11 gen_random   n=200000
tc t12 gen_random   n=200000 min_b=-400000000
tc t13 gen_notnever n=2
tc t14 gen_notnever n=6
tc t15 gen_notnever n=30 min_b=-5   max_b=5
tc t16 gen_notnever n=30 circlesize=25 min_b=-3   max_b=3
tc t17 gen_notnever n=30 circlesize=4 min_b=-3   max_b=3
tc t18 gen_notnever n=100
tc t19 gen_notnever n=999
tc t20 gen_notnever n=1000 min_b=-5   max_b=5
tc t21 gen_notnever n=1000 min_b=-1   max_b=1
tc t22 gen_notnever n=1000 min_b=0    max_b=0
tc t23 gen_notnever n=12345
tc t24 gen_notnever n=200000
tc t25 gen_notnever n=200000
tc t26 gen_notnever n=200000 circlesize=2
tc t27 gen_notnever n=200000 circlesize=5
tc t28 gen_notnever n=200000 circlesize=199000
tc t29 gen_notnever n=200000 circlesize=200000
tc t30 gen_notnever n=200000 min_b=999999990
tc t31 gen_notnever n=199997 max_b=10000
tc t32 gen_maxans   n=30
tc t33 gen_maxans   n=1000
tc t34 gen_maxans   n=10000
tc t35 gen_maxans   n=200000
tc t36 gen_maxans   n=200000 start=0
tc t37 gen_maxans   n=200000 start=1
tc t38 gen_maxans   n=200000 start=199999
tc t39 gen_maxans   n=200000 start=199998
tc t40 gen_compressiontest n=200000
tc t41 gen_star n=200000
tc_manual ../manual-tests/zerocircle1.in
tc_manual ../manual-tests/zerocircle2.in
