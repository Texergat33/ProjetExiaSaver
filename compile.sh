#!/bin/sh
# Compiles all the executables of the project
gcc source/eXiaSaver.c source/launcher.c lib/fork/fork.c lib/rand/rand.c lib/stats/hist.c -o eXiaSaver
gcc eXiaSaver1/source/eXiaSaver1.c lib/PBM/PBM.c -o eXiaSaver1/eXiaSaver1
gcc eXiaSaver2/source/eXiaSaver2.c lib/PBM/PBM.c -o eXiaSaver2/eXiaSaver2
gcc eXiaSaver3/source/eXiaSaver3.c eXiaSaver3/source/launcher.c lib/PBM/PBM.c lib/fork/fork.c lib/rand/rand.c -o eXiaSaver3/eXiaSaver3
echo "Done."
