build-par:
	xcrun /opt/opencilk/bin/clang++ src/parallel_qsort.cpp -o bin/parallel_qsort -O3 -fopencilk

bench-par: build-par
	CILK_NWORKERS=4 ./bin/parallel_qsort 100000000 5 > results/bench_parallel.txt

build-seq:
	xcrun /opt/opencilk/bin/clang++ src/serial_qsort.cpp -o bin/serial_qsort -O3 -fopencilk

bench-seq: build-seq
	./bin/serial_qsort 100000000 5 > results/bench_serial.txt