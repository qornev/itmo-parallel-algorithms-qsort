#include <iostream>
#include <cilk/cilk.h>

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int* partition(int* left, int* right) {
    int pivot = *right;
    int* i = left - 1;
    int* j = left;
    for (; j < right; j++) {
        if (*j <= pivot) {
            i++;
            swap(*j, *i);
        }
    }
    i++;
    swap(*j, *i);
    return i;
}

void qsort(int* left, int* right) {
    if (left < right) {
        int* middle = partition(left, right); 
        cilk_spawn qsort(left, middle - 1);
        qsort(middle + 1, right);
    }
}

int main(int argc, char* argv[]) {
    std::srand(std::time(nullptr));

    int n = 100000000;
    if (argc > 1)
        n = atoi(argv[1]);

    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = std::rand() % n;
        //std::cout << a[i] << ' ';
    }

    std::cout << std::endl << "Sorting " << n << " integers" << std::endl;
    qsort(a, a+n);

    //for (int i = 0; i < n; i++)
    //    std::cout << a[i] << ' ';
}
