#!/bin/sh
# Compiles all the executables of the project
gcc source/eXiaSaver.c source/launcher.c -o eXiaSaver
gcc eXiaSaver1/source/eXiaSaver1.c PBM/PBM.c -o eXiaSaver1/eXiaSaver1
gcc eXiaSaver3/source/eXiaSaver3.c -o eXiaSaver3/eXiaSaver3
