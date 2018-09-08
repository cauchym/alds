#include <iostream>
using namespace std;

int selectionSort(int A[], int N) {
    int counter;
    for(int i = 0; i < N; i++) {
        int tmp;
        int minj = i;
        for (int j = i; j < N; j++) { // minjの位置を特定
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (A[i] != A[minj]) { // A[minj](未ソートの中で最小の要素)とA[i](未ソートの中で最小の位置の要素)を比較して交換
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            counter++;
        }
    }
    return counter;
}

int main() {
    int n, A[100], counter;
    cin >> n;
    for(int i; i < n; i++) {
        cin >> A[i];
    }
    counter = selectionSort(A, n);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << counter << endl;
}