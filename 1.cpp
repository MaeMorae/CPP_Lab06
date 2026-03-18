#include<iostream>
#include<windows.h>
using namespace std;

const int N = 10;
int main() {
    SetConsoleOutputCP(CP_UTF8);
    float array1[N] = {1.5, 3.42, 0, 6.3, 7.0, 0, 34.111, 5.8467, 0, 69.67};
    float array_temporary[N];
    float mean_v0, mean_v1 = 0;
    int count0 = 0;
    int i;
    for (i = 0; i < N; i++) {
        mean_v0 += array1[i];
        if (array1[i] == 0) count0++;
        else array_temporary[i-count0] = array1[i];
    }
    float array2[N-count0];
    for (i = 0; i < N-count0; i++) {
        array2[i] = array_temporary[i];
    }
    float mean_v2 = mean_v0 / (N-count0);
    mean_v0 /= N;
    for (i = 0; i < N; i++) {
        if (array1[i] == 0) array1[i] = mean_v0;
        mean_v1 += array1[i];
    }
    mean_v1 /= N;
    if (mean_v1 > mean_v2 || mean_v1 < mean_v2) {
        if (mean_v1 > mean_v2) {
            printf("Среднее первого массива больше второго: %f > %f\n", mean_v1, mean_v2);
        }
        if (mean_v1 < mean_v2) {
            printf("Среднее первого массива меньше второго: %f < %f\n", mean_v1, mean_v2);
        }
    }
    else {
        printf("Среднее первого массива равно второму: %f\n", mean_v1);
    }
    for (i = 0; i < N; i++) {
        printf("%f ", array1[i]);
    }
    cout << endl;
    for (i = 0; i < N-count0; i++) {
        printf("%f ", array2[i]);
    }
}
