# CW1. Parallel QuickSort

## Problem

Нужно реализовать quicksort. Требуется написать последовательную версию алгоритма (seq) и паралелльную версию (par). Взять случайный массив из $10^8$ элементов и отсортировать (Усреднить по 5 запускам). Сравнить время работы par на 4 процессах и seq на одном процессоре - должно быть раза в 3 быстрее.

## Solution

Было реализовано два алгоритма quicksort:

- Параллельный с помощью OpenCilk -- `src/parallel_qsort.cpp`;
- Последовательный -- `src/serial_qsort.cpp`.

Скрипты запусков находятся в Makefile.

Результаты запусков можно посмотреть в файлах `results/bench_parallel.txt` и `results/bench_serial.txt`.

```
# results/bench_parallel.txt

4382
4312
3943
4028
4471
```

```
# results/bench_serial.txt

12483
12391
12533
12413
12686
```

Среднее время параллельного алгоритма ~4227.2 ms, а последовательного -- ~12501 ms. Параллельный алгоритм быстрее последовательного в 2.96 раза.
