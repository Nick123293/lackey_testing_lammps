#!/bin/bash


srun -p nocona -N 1 -n 1 -X ../../../../valgrind-3.24.0/coregrind/valgrind --tool=lackey --trace-mem=yes --log-file=lackey.out lmp -in input.lammps bash -l -c "module load gcc/10.1.0 openmpi/4.1.4 lammps/20230802-mpi-openmp"

