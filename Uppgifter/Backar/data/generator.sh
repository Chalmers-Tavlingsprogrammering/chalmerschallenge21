#!/bin/bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

# For unlimited stack:
# ulimit -s unlimited

# Choose your solution
use_solution dijkstra.cpp

# Compile generators
compile gen_random.py

# Generate answers to sample cases (optional)
sample 01
sample 02

# Note: tc automatically adds a deterministic, pseudo-random seed argument to your generator
tc t1 gen_random n=4
tc t2 gen_random n=6
tc t3 gen_random n=10
#tc_manual ../manual-tests/1.in

