#include <iostream>
#include <algorithm>
using namespace std;

int bubbleSort(int A[], int N) {
    bool flag = 1;
    int count = 0;
    for  (int i; flag; i++) { //未ソート部分の先頭idx
        flag = 0;
        for (int j = N - 1; j >= i+ 1; j--) {
            if (A[j] < A[j-1]) { // <=としないことで安定に
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                count++;
            }
        }
    }
    return count;
}

int main() {
    int A[100], n, count;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    count = bubbleSort(A, n);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
}
