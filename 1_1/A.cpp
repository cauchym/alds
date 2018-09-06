#include <iostream>
#include <string>
using namespace std;
static const int MAX = 101;

void outputArray(int A[MAX], int len) {
    for (int i = 0; i < len; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[MAX], int N) {
    for (int i = 1; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        outputArray(A, N);
    }
}

int main() {
    int A[MAX], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    outputArray(A, n);
    insertionSort(A, n);
}
