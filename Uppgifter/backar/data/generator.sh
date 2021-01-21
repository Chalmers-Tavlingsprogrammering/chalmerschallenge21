#!/bin/bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

# For unlimited stack:
# ulimit -s unlimited

# Choose your solution
use_solution dijkstra.cpp

# Compile generators
compile gen_random.py
compile gen_star.py

# Generate answers to sample cases (optional)
sample 01
sample 02

# Note: tc automatically adds a deterministic, pseudo-random seed argument to your generator
tc t1 gen_random  n=4     m=2
tc t2 gen_random  n=4     m=4
tc t3 gen_random  n=6     m=3
tc t4 gen_random  n=6     m=6
tc t5 gen_random  n=6     m=12
tc t6 gen_random  n=10    m=5
tc t7 gen_random  n=10    m=10
tc t8 gen_random  n=10    m=20
tc t9 gen_random  n=20    m=10
tc t10 gen_random n=20    m=20
tc t11 gen_random n=20    m=80
tc t12 gen_random n=80    m=40
tc t13 gen_random n=80    m=80
tc t14 gen_random n=80    m=300
tc t15 gen_random n=200   m=100
tc t16 gen_random n=200   m=200
tc t17 gen_random n=200   m=500
tc t18 gen_random n=1000  m=800
tc t19 gen_random n=1000  m=2000
tc t20 gen_random n=2000  m=1000
tc t21 gen_random n=2000  m=5000
tc t22 gen_random n=4000  m=10000
tc t23 gen_random n=10000 m=50000
tc t24 gen_random n=20000 m=100000
tc s0 gen_star n=1000
tc s1 gen_star n=5000
tc s2 gen_star n=10000
tc s3 gen_star n=20000

#tc_manual ../manual-tests/1.in

