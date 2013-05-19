#!/bin/sh -e

# Directives to pass in call to qsub:
# -o localhost:${STAN_HOME}/hotfoot/${GIT_COMMIT}/test-distributions/stdout
# -e localhost:${STAN_HOME}/hotfoot/${GIT_COMMIT}/test-distributions/stderr

# Fixed directives:
#PBS -N test-distributions
#PBS -W group_list=<hpcstats>
#PBS -l nodes=1,walltime=00:00:30,mem=2gb
#PBS -M bg2382@columbia.edu
#PBS -m n
#PBS -V

echo "Start time:"
date

cd ${STAN_HOME}
time make CC=${CC} ${TEST_DISTRIBUTIONS_ARRAY[${PBS_ARRAYID}]}

echo "End time:"
date

echo "test successful"

# End of script