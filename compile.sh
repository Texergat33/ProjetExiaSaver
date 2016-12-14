#!/bin/sh
# Compiles all the executables of the project
gcc source/eXiaSaver.c source/launcher.c lib/fork/fork.c lib/rand/rand.c -o eXiaSaver
gcc eXiaSaver1/source/eXiaSaver1.c lib/PBM/PBM.c -o eXiaSaver1/eXiaSaver1
gcc eXiaSaver3/source/eXiaSaver3.c eXiaSaver3/source/launcher.c lib/PBM/PBM.c lib/fork/fork.c lib/rand/rand.c -o eXiaSaver3/eXiaSaver3
echo "Done."