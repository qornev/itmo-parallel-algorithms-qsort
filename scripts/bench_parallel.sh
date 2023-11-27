cd "$(dirname "$0$")"
mkdir -p ../bin
mkdir -p ../results

SRC_PATH=../src/parallel_qsort.cpp
BIN_PATH=../bin/parallel_qsort
xcrun /opt/opencilk/bin/clang++ $SRC_PATH -o $BIN_PATH -O3 -fopencilk

TMP_FILE=output.txt
REPORT_PATH=../results/bench_parallel.txt
for i in `seq 5`
do
	/usr/bin/time -p -a -o $REPORT_PATH env CILK_NWORKERS=4 $BIN_PATH
done
grep real $REPORT_PATH | grep -oe '\d*,\d*$' > $TMP_FILE && mv $TMP_FILE $REPORT_PATH
