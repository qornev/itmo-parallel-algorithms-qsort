#include <iostream>
using namespace std;
using namespace std::chrono;

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
        qsort(left, middle - 1);
        qsort(middle + 1, right);
    }
}

bool check(int* start, int n) {
    int prev = *start;
    for (int i = 1; i < n; i++) {
        int cur = *(start + i);
        if (prev > cur)
            return false;
        prev = cur;
    }
    return true;
}

int main(int argc, char* argv[]) {
    std::srand(std::time(nullptr));

    int n = 100000000;
    if (argc > 1)
        n = atoi(argv[1]);

    int n_repeats = 1;
    if (argc > 2)
        n_repeats = atoi(argv[2]);

    for (int i = 0; i < n_repeats; i++) {
        int *a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = rand() % n;
        }

        cout << "Sorting " << n << " integers" << endl;
        auto start_time = high_resolution_clock::now();
        
        qsort(a, a+n);

        auto stop_time = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop_time - start_time);
        cout << "Time: " << duration.count() << " millisec" << endl;

        if (check(a, n))
            cout << "All values are sorted in ascending order" << endl << endl;
        else
            cout << "ERROR: Values are not sorted" << endl << endl;   
    }
}
