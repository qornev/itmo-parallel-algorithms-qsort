cd "$(dirname "$0")"
mkdir -p ../bin
mkdir -p ../results

SRC_PATH=../src/serial_qsort.cpp
BIN_PATH=../bin/serial_qsort
g++ $SRC_PATH -o $BIN_PATH -O3

TMP_FILE=output.txt
REPORT_PATH=../results/bench_serial.txt
for _ in `seq 5`
do
	/usr/bin/time -p -a -o $REPORT_PATH $BIN_PATH
done
grep real $REPORT_PATH | grep -oe '\d*,\d*$' > $TMP_FILE && mv $TMP_FILE $REPORT_PATH
